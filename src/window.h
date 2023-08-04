#ifndef WINDOW_H
#define WINDOW_H

#include "OpenGl.h"
#include "Colors.h"
#include "util/Error.h"
#include <stdio.h>

typedef enum WindowConfig {
    Resizeable = 0x1
} WindowConfig;

enum Window_Error {
    GLFWInitializationFailed = 1,
    WindowCreationFailed,
    GLADLoadFailed
};



typedef struct Window {
    GLuint Size[2];
    GLFWwindow* window;
} Window;


//initializes OpenGL and fills data into the window struct
enum Window_Error createWindow(char* name, Window* window, WindowConfig config);
void destroyWindow(Window* w);
char* Window_GetError(enum Window_Error err);



#endif