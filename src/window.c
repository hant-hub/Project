#include "window.h"



enum Window_Error createWindow(char* name, Window* window, WindowConfig config) {
    
    
    if (!glfwInit()){
        return GLFWInitializationFailed;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_RESIZABLE, config | Resizeable);

    window->window = glfwCreateWindow(window->Size[0], window->Size[1], name, NULL, NULL);
    if (!window->window) {
        printf(ERROR, "Critical Error: Window Creation Failed");
        glfwTerminate();
        return WindowCreationFailed;
    }

    glfwMakeContextCurrent(window->window);

    //load opengl functions for rendering using GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwDestroyWindow(window->window);
        glfwTerminate();
        return GLADLoadFailed;
    }

    return NoError;
}

void destroyWindow(Window* w) {
    glfwDestroyWindow(w->window);
    glfwTerminate();
}


char* Window_GetError(enum Window_Error err) {
    switch(err){
        case GLFWInitializationFailed:
            return "GLFW Failed to Initialize";
        break;

        case WindowCreationFailed:
            return "GLFW Failed to Create Window";
        break;

        case GLADLoadFailed:
            return "GLAD failed to Load OpenGl Functions";
        break;

        default:
            return "Unknown Error";
        break;
    };
}