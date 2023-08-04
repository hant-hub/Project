#ifndef FILE_H
#define FILE_H
#include "Error.h"
#include <stdio.h>
#include <stdlib.h>


//Generic data pointer for loading memory
typedef struct Buffer {
    void* data;
    size_t length;
} file_buffer;

enum file_Error {
    FailedOpen = 1,
    UnexpectedEOF,
    FailedRead
};


enum file_Error file_LoadFileToMemory(const char* filepath, file_buffer* output);
char* file_GetError(enum file_Error err);


#endif