#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const char *vert_shader_src =
    "attribute vec4 a_position;\n"
    "attribute vec2 a_texcoord;\n"
    "varying vec2 v_texcoord;\n"
    "void main() {\n"
    "  gl_Position = a_position;\n"
    "  v_texcoord = a_texcoord;\n"
    "}\n";

static const char *frag_shader_src =
    "precision mediump float;\n"
    "varying vec2 v_texcoord;\n"
    "uniform sampler2D u_texture;\n"
    "uniform float u_time;\n"
    "void main() {\n"
    "  vec2 uv = v_texcoord;\n"
    "  vec4 color = texture2D(u_texture, uv);\n"
    "  float pulse = 0.5 + 0.5 * sin(u_time * 2.0);\n"
    "  color.rgb = mix(color.rgb, vec3(1.0, 0.3, 0.3), pulse * 0.3);\n"
    "  gl_FragColor = color;\n"
    "}\n";

static const char *fbo_frag_shader_src =
    "precision mediump float;\n"
    "varying vec2 v_texcoord;\n"
    "uniform float u_time;\n"
    "void main() {\n"
    "  vec2 uv = v_texcoord - 0.5;\n"
    "  float r = length(uv);\n"
    "  float angle = atan(uv.y, uv.x) + u_time;\n"
    "  vec3 color = 0.5 + 0.5 * cos(angle + vec3(0.0, 2.0, 4.0));\n"
    "  float alpha = smoothstep(0.4, 0.3, r);\n"
    "  gl_FragColor = vec4(color * alpha, 1.0);\n"
    "}\n";

typedef struct {
    GLuint program;
    GLint time_loc;
    GLint tex_loc;
} ShaderInfo;

static GLuint load_shader(GLenum type, const char *src) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        char log[512];
        glGetShaderInfoLog(shader, sizeof(log), NULL, log);
        fprintf(stderr, "Shader compile error: %s\n", log);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

static GLuint create_program(const char *vert_src, const char *frag_src) {
    GLuint vert = load_shader(GL_VERTEX_SHADER, vert_src);
    GLuint frag = load_shader(GL_FRAGMENT_SHADER, frag_src);

    GLuint program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        char log[512];
        glGetProgramInfoLog(program, sizeof(log), NULL, log);
        fprintf(stderr, "Program link error: %s\n", log);
        glDeleteProgram(program);
        return 0;
    }

    glDeleteShader(vert);
    glDeleteShader(frag);
    return program;
}

static ShaderInfo create_shader_info(const char *vert_src, const char *frag_src) {
    ShaderInfo info;
    info.program = create_program(vert_src, frag_src);
    info.time_loc = glGetUniformLocation(info.program, "u_time");
    info.tex_loc = glGetUniformLocation(info.program, "u_texture");
    return info;
}

typedef struct {
    GLuint fbo;
    GLuint texture;
    int width;
    int height;
} FBO;

static int create_fbo(FBO *fbo, int width, int height) {
    glGenFramebuffers(1, &fbo->fbo);
    glGenTextures(1, &fbo->texture);
    fbo->width = width;
    fbo->height = height;

    glBindTexture(GL_TEXTURE_2D, fbo->texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindFramebuffer(GL_FRAMEBUFFER, fbo->fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo->texture, 0);

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        fprintf(stderr, "FBO incomplete: 0x%x\n", status);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return -1;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return 0;
}

static void destroy_fbo(FBO *fbo) {
    glDeleteFramebuffers(1, &fbo->fbo);
    glDeleteTextures(1, &fbo->texture);
}

static const GLfloat vertices[] = {
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,
};

static const GLfloat texcoords[] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f,
};

static void draw_quad(GLuint prog, ShaderInfo *info, float time) {
    glUseProgram(prog);

    GLint pos_loc = glGetAttribLocation(prog, "a_position");
    GLint tex_loc = glGetAttribLocation(prog, "a_texcoord");

    glEnableVertexAttribArray(pos_loc);
    glVertexAttribPointer(pos_loc, 3, GL_FLOAT, GL_FALSE, 0, vertices);

    glEnableVertexAttribArray(tex_loc);
    glVertexAttribPointer(tex_loc, 2, GL_FLOAT, GL_FALSE, 0, texcoords);

    glUniform1f(info->time_loc, time);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(pos_loc);
    glDisableVertexAttribArray(tex_loc);
}

int main(int argc, char **argv) {
    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;

    EGLint config_attrs[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_NONE
    };

    EGLint ctx_attrs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    EGLint pbuffer_attrs[] = {
        EGL_WIDTH, 800,
        EGL_HEIGHT, 600,
        EGL_NONE
    };

    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display, NULL, NULL);
    eglChooseConfig(display, config_attrs, &config, 1, NULL);
    context = eglCreateContext(display, config, EGL_NO_CONTEXT, ctx_attrs);
    surface = eglCreatePbufferSurface(display, config, pbuffer_attrs);
    eglMakeCurrent(display, surface, surface, context);

    FBO fbo;
    if (create_fbo(&fbo, 256, 256) != 0) {
        fprintf(stderr, "Failed to create FBO\n");
        return 1;
    }

    ShaderInfo fbo_shader = create_shader_info(vert_shader_src, fbo_frag_shader_src);
    ShaderInfo display_shader = create_shader_info(vert_shader_src, frag_shader_src);

    glGenTextures(1, &fbo.texture);

    float time = 0.0f;

    while (time < 10.0f) {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        glViewport(0, 0, fbo.width, fbo.height);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        draw_quad(fbo_shader.program, &fbo_shader, time);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, 800, 600);
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, fbo.texture);
        glUniform1i(display_shader.tex_loc, 0);
        draw_quad(display_shader.program, &display_shader, time);

        eglSwapBuffers(display, surface);
        time += 0.016f;

        usleep(16000);
    }

    destroy_fbo(&fbo);
    glDeleteProgram(fbo_shader.program);
    glDeleteProgram(display_shader.program);

    eglDestroySurface(display, surface);
    eglDestroyContext(display, context);
    eglTerminate(display);

    printf("FBO example completed successfully\n");
    return 0;
}
