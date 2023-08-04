#include "shaders.h"



enum shaders_Error createVertexShader(VertexShader* shader, file_buffer* source){
    *shader = glCreateShader(GL_VERTEX_SHADER);

    const GLchar* vertexCode[] = {source->data};
    GLint vertsize = (GLint)source->length;
    

    glShaderSource(*shader, 1, vertexCode, &vertsize);
    glCompileShader(*shader);
    
    int  success;
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        return VertexCompilationFailed;
    }

    return NoError;

}
enum shaders_Error createFragShader(FragShader* shader, file_buffer* source){
    *shader = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* fragCode[] = {source->data};
    GLint fragsize = (GLint)source->length;
    
    glShaderSource(*shader, 1, fragCode, &fragsize);
    glCompileShader(*shader);
    
    int  success;
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        return FragmentCompilationFailed;
    }

    return NoError;

}

enum shaders_Error createShaderProgram(VertexShader* vert, FragShader* frag, ShaderProgram* prog) {
    *prog = glCreateProgram();
    glAttachShader(*prog, *vert);
    glAttachShader(*prog, *frag);
    glLinkProgram(*prog);

    int success;
    glGetProgramiv(*prog, GL_LINK_STATUS, (int*)&success);
    if(success == GL_FALSE) {
        return ProgramLinkingFailed;
    }

    return NoError;
}


char* shaders_GetError(enum shaders_Error err) {
    switch(err) {
        case VertexCompilationFailed:
            return "Vertex Shader Compilation Failed";
        
        case FragmentCompilationFailed:
            return "Fragment Shader Compilation Failed";

        case ProgramLinkingFailed:
            return "Shader Program Failed to Link";

        default:
            return "Unknown Error";
    };
}
