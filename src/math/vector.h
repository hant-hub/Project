#ifndef VECTOR_H
#define VECTOR_H


//2D vectors

typedef struct vec2f {
    float x;
    float y;
} vec2f;

float vec2f_dot(vec2f a, vec2f b);
vec2f vec2f_add(vec2f a, vec2f b);


typedef struct vec2d {
    double x;
    double y;
} vec2d;

float vec2d_dot(vec2d a, vec2d b);
vec2d vec2d_add(vec2d a, vec2d b);


typedef struct vec2i {
    int x;
    int y;
} vec2i;

float vec2i_dot(vec2i a, vec2i b);
vec2i vec2i_add(vec2i a, vec2i b);

//3D vectors

typedef struct vec3f {
    float x;
    float y;
    float z;
} vec3f;

float vec3f_dot(vec3f a, vec3f b);
vec3f vec3f_add(vec3f a, vec3f b);
vec3f vec3f_cross(vec3f a, vec3f b);


typedef struct vec3d {
    double x;
    double y;
    double z;
} vec3d;

float vec3d_dot(vec3d a, vec3d b);
vec3d vec3d_add(vec3d a, vec3d b);
vec3d vec3d_cross(vec3d a, vec3d b);


typedef struct vec3i {
    int x;
    int y;
    int z;
} vec3i;

float vec3i_dot(vec3i a, vec3i b);
vec3i vec3i_add(vec3i a, vec3i b);
vec3i vec3i_cross(vec3i a, vec3i b);

//4D vectors

typedef struct vec4f {
    float x;
    float y;
    float z;
    float w;
} vec4f;

float vec4f_dot(vec4f a, vec4f b);
vec4f vec4f_add(vec4f a, vec4f b);



typedef struct vec4d {
    double x;
    double y;
    double z;
    double w;
} vec4d;

float vec4d_dot(vec4d a, vec4d b);
vec4d vec4d_add(vec4d a, vec4d b);



typedef struct vec4i {
    int x;
    int y;
    int z;
    int w;
} vec4i;

float vec4i_dot(vec4i a, vec4i b);
vec4i vec4i_add(vec4i a, vec4i b);



#endif