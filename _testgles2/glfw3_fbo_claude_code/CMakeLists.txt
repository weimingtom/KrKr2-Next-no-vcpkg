cmake_minimum_required(VERSION 3.10)
project(fbo_example LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

add_executable(fbo_example src/main.c)
target_link_libraries(fbo_example glfw ${OPENGL_gl_LIBRARY} m)

target_compile_options(fbo_example PRIVATE $<$<CONFIG:Debug>:-g>)
