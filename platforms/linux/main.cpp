#include <memory>
#include <gtk/gtk.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#if MY_USE_MINLIB
#include <stdio.h>
#include <stdlib.h>
 
#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>

#include "engine_api.h"
#include "engine_options.h"

static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

static engine_handle_t _handle = 0;
static engine_result_t create(const char *writablePath, const char *cachePath) {
    engine_handle_t outHandle = 0;
    if (_handle != 0) {
    	return ENGINE_RESULT_OK;
    }
    engine_create_desc_t desc = {sizeof(engine_create_desc_t)};
    desc.api_version = ENGINE_API_VERSION;
    desc.writable_path_utf8 = 0;
    desc.cache_path_utf8 = 0;
    desc.user_data = 0;
    engine_result_t result = engine_create(&desc, &outHandle);
    if (result == ENGINE_RESULT_OK) {
       _handle = outHandle;
    }
    return result;
}

static uint32_t runtimeApiVersion() {
    uint32_t outVersion = 0;
    engine_result_t result = engine_get_runtime_api_version(&outVersion);
    if (result != ENGINE_RESULT_OK) {
	return result;
    }
    return outVersion;
}

static engine_memory_stats_t *getMemoryStats() {
        static engine_memory_stats_t stats = {sizeof(engine_memory_stats_t)};
	if (_handle == 0) {
		return 0;
	}
	engine_result_t result = engine_get_memory_stats(_handle, &stats);
    	if (result != ENGINE_RESULT_OK) {
    		return 0;
    	}
	return &stats;
}

static engine_result_t openGameAsync(const char *gameRootPath, const char *startupScript) {
	return engine_open_game_async(_handle, gameRootPath, startupScript);
}

static engine_result_t tick(int deltaMs=16) {
	return engine_tick(_handle, deltaMs);
}

static engine_result_t destroy() {
	engine_handle_t current = _handle;
	if (current == 0) {
		return ENGINE_RESULT_OK;
	}
	engine_result_t result = engine_destroy(current);
	if (result == ENGINE_RESULT_OK) {
		_handle = 0;
	}
	return result;
}

#else
#include "environ/cocos2d/AppDelegate.h"

#include "environ/ui/MainFileSelectorForm.h"
#endif

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);
    spdlog::set_level(spdlog::level::debug);

    static auto core_logger = spdlog::stdout_color_mt("core");
    static auto tjs2_logger = spdlog::stdout_color_mt("tjs2");
    static auto plugin_logger = spdlog::stdout_color_mt("plugin");
    // 将输入的参数也就是输入文件转为wstring
    if(argc > 1) {
#if MY_USE_MINLIB
#else
        TVPMainFileSelectorForm::filePath = argv[1];
#endif
    }
    spdlog::set_default_logger(core_logger);

#if MY_USE_MINLIB
//    GLuint shader_program, vbo;
//    GLint pos;
    GLFWwindow* window;
 
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(WIDTH, HEIGHT, __FILE__, NULL, NULL);
    glfwMakeContextCurrent(window);
 
    printf("GL_VERSION  : %s\n", glGetString(GL_VERSION) );
    printf("GL_RENDERER : %s\n", glGetString(GL_RENDERER) );

engine_result_t result = create(0, 0);
if (result != ENGINE_RESULT_OK) {
printf("create() failed, result== %d: %s\n", result, engine_get_last_error(_handle));
	return -1;
}

uint32_t api_version = runtimeApiVersion();
printf("api_version == 0x%x\n", api_version);
//api_version == 1000000

engine_memory_stats_t *stats = getMemoryStats();
//Log.i("krkr2", "stats == " + stats);

//"/home/wmt/KrKr2-Next/_testdata/"
openGameAsync("/home/wmt/KrKr2-Next/_testdata/Data.xp3", "/home/wmt/KrKr2-Next/_testdata/");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

engine_result_t tick_result = tick();
if (tick_result != ENGINE_RESULT_OK && tick_result != -2) {
	printf("tick() == %d\n", tick_result);
}


        glfwSwapBuffers(window);
    }

    destroy();
    glfwTerminate();

    return EXIT_SUCCESS;
#else
    static auto pAppDelegate = std::make_unique<TVPAppDelegate>();
    return pAppDelegate->run();
#endif    
}
