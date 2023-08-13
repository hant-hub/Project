#include "vector.h"
//2D vectors

float util_math_vec2f_dot(vec2f a, vec2f b) {
    return (a.x * b.x) + (a.y * b.y);
}
vec2f util_math_vec2f_add(vec2f a, vec2f b) {
    return (vec2f){a.x + b.x, a.y + b.y};
}

double util_math_vec2d_dot(vec2d a, vec2d b) {
    return (a.x * b.x) + (a.y * b.y);
}
vec2d util_math_vec2d_add(vec2d a, vec2d b) {
    return (vec2d){a.x + b.x, a.y + b.y};
}

int util_math_vec2i_dot(vec2i a, vec2i b) {
    return (a.x * b.x) + (a.y * b.y);
}
vec2i util_math_vec2i_add(vec2i a, vec2i b) {
    return (vec2i){a.x + b.x, a.y + b.y};
}

//3D vectors

float util_math_vec3f_dot(vec3f a, vec3f b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
vec3f util_math_vec3f_add(vec3f a, vec3f b) {
    return (vec3f){a.x + b.x, a.y + b.y, a.z + b.z};
}
//right handed
vec3f util_math_vec3f_cross(vec3f a, vec3f b) {
    vec3f c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}

double util_math_vec3d_dot(vec3d a, vec3d b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
vec3d util_math_vec3d_add(vec3d a, vec3d b) {
    return (vec3d){a.x + b.x, a.y + b.y, a.z + b.z};
}
//right handed
vec3d util_math_vec3d_cross(vec3d a, vec3d b) {
    vec3d c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}
int util_math_vec3i_dot(vec3i a, vec3i b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
vec3i util_math_vec3i_add(vec3i a, vec3i b) {
    return (vec3i){a.x + b.x, a.y + b.y, a.z + b.z};
}
//right handed
vec3i util_math_vec3i_cross(vec3i a, vec3i b) {
    vec3i c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}


//4D vectors
float util_math_vec4f_dot(vec4f a, vec4f b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
vec4f util_math_vec4f_add(vec4f a, vec4f b) {
    return (vec4f){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
double util_math_vec4d_dot(vec4d a, vec4d b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
vec4d util_math_vec4d_add(vec4d a, vec4d b) {
    return (vec4d){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
int util_math_vec4i_dot(vec4i a, vec4i b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
vec4i util_math_vec4i_add(vec4i a, vec4i b) {
    return (vec4i){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}


//n-vectors

enum vector_Error util_math_vecNf_dot(float* out, vector_n_f* a, vector_n_f* b) {
    if (a->size != b->size) return IncorrectSizes;

    *out = 0.0f;
    for (int i = 0; i < a->size; i++) {
        *out += a->components[i] * b->components[i];
    }
    
    return NoError;
}
enum vector_Error util_math_vecNf_add(vector_n_f* out, vector_n_f* a, vector_n_f* b) {
    if (a->size != b->size) return IncorrectSizes;

    out->size = a->size;
    out->components = malloc(a->size * sizeof(float));
    for (int i = 0; i < a->size; i++) {
        out->components[i] = a->components[i] + b->components[i];
    }

    return NoError;
}
enum vector_Error util_math_vecNd_dot(double* out, vector_n_d* a, vector_n_d* b){
    if (a->size != b->size) return IncorrectSizes;

    *out = 0.0f;
    for (int i = 0; i < a->size; i++) {
        *out += a->components[i] * b->components[i];
    }
    
    return NoError;
}
enum vector_Error util_math_vecNd_add(vector_n_d* out, vector_n_d* a, vector_n_d* b) {
    if (a->size != b->size) return IncorrectSizes;

    out->size = a->size;
    out->components = malloc(a->size * sizeof(double));
    for (int i = 0; i < a->size; i++) {
        out->components[i] = a->components[i] + b->components[i];
    }

    return NoError;
}
enum vector_Error util_math_vecNi_dot(int* out, vector_n_i* a, vector_n_i* b){
    if (a->size != b->size) return IncorrectSizes;

    *out = 0.0f;
    for (int i = 0; i < a->size; i++) {
        *out += a->components[i] * b->components[i];
    }
    
    return NoError;
}
enum vector_Error util_math_vecNi_add(vector_n_i* out, vector_n_i* a, vector_n_i* b) {
    if (a->size != b->size) return IncorrectSizes;

    out->size = a->size;
    out->components = malloc(a->size * sizeof(int));
    for (int i = 0; i < a->size; i++) {
        out->components[i] = a->components[i] + b->components[i];
    }

    return NoError;
}
