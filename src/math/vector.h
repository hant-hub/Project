#ifndef VECTOR_H
#define VECTOR_H
#include "../util/Error.h"
#include <stdlib.h>

//2D vectors

typedef struct vec2f {
    float x;
    float y;
} vec2f;

float util_math_vec2f_dot(vec2f a, vec2f b);
vec2f util_math_vec2f_add(vec2f a, vec2f b);


typedef struct vec2d {
    double x;
    double y;
} vec2d;

double util_math_vec2d_dot(vec2d a, vec2d b);
vec2d util_math_vec2d_add(vec2d a, vec2d b);


typedef struct vec2i {
    int x;
    int y;
} vec2i;

int util_math_vec2i_dot(vec2i a, vec2i b);
vec2i util_math_vec2i_add(vec2i a, vec2i b);

//3D vectors

typedef struct vec3f {
    float x;
    float y;
    float z;
} vec3f;

float util_math_vec3f_dot(vec3f a, vec3f b);
vec3f util_math_vec3f_add(vec3f a, vec3f b);
vec3f util_math_vec3f_cross(vec3f a, vec3f b);


typedef struct vec3d {
    double x;
    double y;
    double z;
} vec3d;

double util_math_vec3d_dot(vec3d a, vec3d b);
vec3d util_math_vec3d_add(vec3d a, vec3d b);
vec3d util_math_vec3d_cross(vec3d a, vec3d b);


typedef struct vec3i {
    int x;
    int y;
    int z;
} vec3i;

int util_math_vec3i_dot(vec3i a, vec3i b);
vec3i util_math_vec3i_add(vec3i a, vec3i b);
vec3i util_math_vec3i_cross(vec3i a, vec3i b);

//4D vectors

typedef struct vec4f {
    float x;
    float y;
    float z;
    float w;
} vec4f;

float util_math_vec4f_dot(vec4f a, vec4f b);
vec4f util_math_vec4f_add(vec4f a, vec4f b);



typedef struct vec4d {
    double x;
    double y;
    double z;
    double w;
} vec4d;

double util_math_vec4d_dot(vec4d a, vec4d b);
vec4d util_math_vec4d_add(vec4d a, vec4d b);



typedef struct vec4i {
    int x;
    int y;
    int z;
    int w;
} vec4i;

int util_math_vec4i_dot(vec4i a, vec4i b);
vec4i util_math_vec4i_add(vec4i a, vec4i b);


enum vector_Error{
    IncorrectSizes = NoError+1
};


typedef struct vector_n_f {
    unsigned short size;
    float* components; 
}vector_n_f;

enum vector_Error util_math_vecNf_dot(float* out, vector_n_f* a, vector_n_f* b);
enum vector_Error util_math_vecNf_add(vector_n_f* out, vector_n_f* a, vector_n_f* b);

typedef struct vector_n_d {
    unsigned short size;
    double* components; 
}vector_n_d;

enum vector_Error util_math_vecNd_dot(double* out, vector_n_d* a, vector_n_d* b);
enum vector_Error util_math_vecNd_add(vector_n_d* out, vector_n_d* a, vector_n_d* b);

typedef struct vector_n_i {
    unsigned short size;
    int* components; 
}vector_n_i;

enum vector_Error util_math_vecNi_dot(int* out, vector_n_i* a, vector_n_i* b);
enum vector_Error util_math_vecNi_add(vector_n_i* out, vector_n_i* a, vector_n_i* b);


#endif