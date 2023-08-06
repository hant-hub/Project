cmake_minimum_required(VERSION 3.16.3)


project("project")


execute_process(
    COMMAND bash -c "../src/shaders/compile.sh"
)

add_executable(test)

add_subdirectory(Lib/glfw)
include_directories(Lib/glfw/include/GLFW)
target_link_libraries(test glfw ${GLFW_LIBRARIES})

add_library(glad)
add_subdirectory(Lib/glad)
target_link_libraries(test glad)

target_sources(test PUBLIC 
    main.c 
    Colors.h 
    OpenGl.h
    window.h
    window.c
    shaders.h
    shaders.c)
add_subdirectory(util)
add_subdirectory(math)

target_compile_options(test PRIVATE -Wall -Wextra -Werror)

