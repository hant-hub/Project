#include "file.h"



enum file_Error file_LoadFileToMemory(const char* filepath, file_buffer* output) {
    //open file and check if valid
    FILE* handle = fopen(filepath, "r");

    if (handle == NULL) {
        return FailedOpen;
    }

    //get length of file
    fseek(handle, 0L, SEEK_END);
    output->length = ftell(handle);
    output->data = malloc(output->length);
    rewind(handle);


    //dump file contents to buffer
    size_t success = fread(output->data, 1, output->length, handle);
    if (success != output->length) {
        if (feof(handle)) return UnexpectedEOF;
        if (ferror(handle)) return FailedRead;
    }

    fclose(handle);
    return NoError;
}

char* file_GetError(enum file_Error err){
    switch(err) {
        case FailedOpen:
            return "Failed to Open File";
        
        case UnexpectedEOF:
            return "Unexpected EOF marker";

        case FailedRead:
            return "Failed to Read File";

        default:
            return "Unknown Error";
    }
}