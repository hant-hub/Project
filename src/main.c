#include "OpenGl.h"
#include "util/Error.h"
#include "Colors.h"
#include "util/file.h"
#include "window.h"
#include "shaders.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Vertex {
    float pos[2];
    float color[3];
} Vertex;



const Vertex vertices[] = {
    {{-0.5f, -0.5f}, {ORANGE}},
    {{0.5f, -0.5f}, {ORANGE}},
    {{0.5f,  0.5f}, {ORANGE}},

    {{-0.5f, 0.5f}, {ORANGE}},
    {{0.5f, 0.5f}, {ORANGE}},
    {{-0.5f,  -0.5f}, {ORANGE}}
};  



int main() {

    //initialize glfw for window management
    Window window = {{800, 600}, 0};
    int WindowState = createWindow("test", &window, 0);
    if (WindowState != NoError) {
        printf(ERROR, Window_GetError(WindowState));
        destroyWindow(&window);
        return 1;
    }


    //get Shader Source
    file_buffer vertexSource;
    file_buffer fragSource;

    int VertexState = file_LoadFileToMemory("./shaders/standard.vert", &vertexSource);
    int FragState   = file_LoadFileToMemory("./shaders/standard.frag", &fragSource);
    
    if (VertexState != NoError) {
        printf(ERROR, file_GetError(VertexState));
        destroyWindow(&window);
        return 1;
    }

    if (FragState != NoError) {
        printf(ERROR, file_GetError(FragState));
        destroyWindow(&window);
        return 1;
    }
   
    //create Opengl shader objects
    VertexShader vert;
    FragShader   frag;

    
    int vertState = createVertexShader(&vert, &vertexSource);
    int fragState = createFragShader(&frag, &fragSource);

    free(vertexSource.data);
    free(fragSource.data);

    char infoLog[1024];
    if(vertState != NoError) {
        glGetShaderInfoLog(vert, 1024, NULL, infoLog);
        printf(ERROR, shaders_GetError(vertState));
        printf("%s", infoLog);
        destroyWindow(&window);
        return 1;
    }

    if(fragState != NoError) {
        glGetShaderInfoLog(frag, 1024, NULL, infoLog);
        printf(ERROR, shaders_GetError(fragState));
        printf("%s", infoLog);
        destroyWindow(&window);
        return 1;
    }


    ShaderProgram prog;
    int progState = createShaderProgram(&vert, &frag, &prog);
    if(progState != NoError) {
        glGetProgramInfoLog(prog, 1024, NULL, infoLog);
        printf(ERROR, shaders_GetError(progState));
        printf("%s", infoLog);

        glDeleteProgram(prog);
        glDeleteShader(vert);
	    glDeleteShader(frag);

        destroyWindow(&window);
        return 1;
    }

    glDeleteShader(vert);
    glDeleteShader(frag);


    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float)*2));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteBuffers(1, &vbo);

    

    glUseProgram(prog);
    glBindVertexArray(vao);
    while (!glfwWindowShouldClose(window.window)) {
        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 6);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }


    destroyWindow(&window);
    return 0;
}



