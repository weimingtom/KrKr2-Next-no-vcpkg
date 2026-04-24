#include <GLFW/glfw3.h>
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const char *vertex_shader_src =
    "attribute vec2 a_position;\n"
    "void main() {\n"
    "    gl_Position = vec4(a_position, 0.0, 1.0);\n"
    "}\n";

static const char *fragment_shader_src =
    "precision mediump float;\n"
    "uniform vec4 u_color;\n"
    "void main() {\n"
    "    gl_FragColor = u_color;\n"
    "}\n";

typedef struct {
    GLuint program;
    GLint position_loc;
    GLint color_loc;
} ShaderInfo;

ShaderInfo create_shader_program(void) {
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_src, NULL);
    glCompileShader(fragment_shader);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    ShaderInfo info;
    info.program = program;
    info.position_loc = glGetAttribLocation(program, "a_position");
    info.color_loc = glGetUniformLocation(program, "u_color");
    return info;
}

typedef struct {
    GLuint fbo;
    GLuint texture;
    GLuint depth_buffer;
    int width;
    int height;
} FBO;

FBO create_fbo(int width, int height) {
    FBO fbo;
    fbo.width = width;
    fbo.height = height;

    glGenFramebuffers(1, &fbo.fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);

    glGenTextures(1, &fbo.texture);
    glBindTexture(GL_TEXTURE_2D, fbo.texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fbo.texture, 0);

    glGenRenderbuffers(1, &fbo.depth_buffer);
    glBindRenderbuffer(GL_RENDERBUFFER, fbo.depth_buffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, fbo.depth_buffer);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        fprintf(stderr, "FBO creation failed!\n");
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return fbo;
}

void destroy_fbo(FBO *fbo) {
    glDeleteFramebuffers(1, &fbo->fbo);
    glDeleteTextures(1, &fbo->texture);
    glDeleteRenderbuffers(1, &fbo->depth_buffer);
}

void draw_scene(ShaderInfo *shader, float time) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shader->program);

    float colors[4][4] = {
        {1.0f, 0.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 0.0f, 1.0f},
        {0.0f, 0.0f, 1.0f, 1.0f},
        {1.0f, 1.0f, 0.0f, 1.0f}
    };

    for (int i = 0; i < 4; i++) {
        float angle = time + i * 1.57078f;
        float offset = 0.5f * sinf(angle);
        float x = offset;
        float y = (i - 1.5f) * 0.3f;

        float size = 0.2f;
        float vertices[12] = {
            x - size, y - size,
            x + size, y - size,
            x - size, y + size,
            x - size, y + size,
            x + size, y - size,
            x + size, y + size
        };

        glVertexAttribPointer(shader->position_loc, 2, GL_FLOAT, GL_FALSE, 0, vertices);
        glEnableVertexAttribArray(shader->position_loc);

        glUniform4fv(shader->color_loc, 1, colors[i]);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

int main(void) {
    if (!glfwInit()) {
        fprintf(stderr, "GLFW init failed\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

    GLFWwindow *window = glfwCreateWindow(800, 600, "FBO Example", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Window creation failed\n");
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    ShaderInfo shader = create_shader_program();
    FBO fbo = create_fbo(800, 600);

    while (!glfwWindowShouldClose(window)) {
        float time = (float)glfwGetTime();

        glBindFramebuffer(GL_FRAMEBUFFER, fbo.fbo);
        glViewport(0, 0, fbo.width, fbo.height);
        draw_scene(&shader, time);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.program);

        glBindTexture(GL_TEXTURE_2D, fbo.texture);

        float quad_vertices[12] = {
            -0.8f, -0.6f,
             0.8f, -0.6f,
            -0.8f,  0.6f,
            -0.8f,  0.6f,
             0.8f, -0.6f,
             0.8f,  0.6f
        };

        glVertexAttribPointer(shader.position_loc, 2, GL_FLOAT, GL_FALSE, 0, quad_vertices);
        glEnableVertexAttribArray(shader.position_loc);

        GLint tex_loc = glGetUniformLocation(shader.program, "u_color");
        glUniform4f(tex_loc, 1.0f, 1.0f, 1.0f, 1.0f);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    destroy_fbo(&fbo);
    glDeleteProgram(shader.program);
    glfwTerminate();
    return 0;
}
