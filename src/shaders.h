#ifndef SHADERS_H
#define SHADERS_H

#include "OpenGl.h"
#include "util/Error.h"
#include "util/file.h"

enum shaders_Error {
    VertexCompilationFailed = NoError + 1,
    FragmentCompilationFailed,
    ProgramLinkingFailed
};


typedef GLuint VertexShader;
typedef GLuint FragShader;
typedef GLuint ShaderProgram;

enum shaders_Error createVertexShader(VertexShader* shader, file_buffer* source);
enum shaders_Error createFragShader(FragShader* shader, file_buffer* source);
enum shaders_Error createShaderProgram(VertexShader* vert, FragShader* frag, ShaderProgram* prog);

char* shaders_GetError(enum shaders_Error err);

#endif