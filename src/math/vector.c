#include "vector.h"
//2D vectors

float vec2f_dot(vec2f a, vec2f b) {
    return (a.x * b.x) + (a.y * b.y);
}
vec2f vec2f_add(vec2f a, vec2f b) {
    return (vec2f){a.x + b.x, a.y + b.y};
}

float vec2d_dot(vec2d a, vec2d b) {
    return (a.x * b.x) + (a.y * b.y);
}
vec2d vec2d_add(vec2d a, vec2d b) {
    return (vec2d){a.x + b.x, a.y + b.y};
}

int vec2i_dot(vec2i a, vec2i b) {
    return (a.x * b.x) + (a.y * b.y);
}
vec2i vec2i_add(vec2i a, vec2i b) {
    return (vec2i){a.x + b.x, a.y + b.y};
}

//3D vectors

float vec3f_dot(vec3f a, vec3f b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
vec3f vec3f_add(vec3f a, vec3f b) {
    return (vec3f){a.x + b.x, a.y + b.y, a.z + b.z};
}
//right handed
vec3f vec3f_cross(vec3f a, vec3f b) {
    vec3f c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}
float vec3d_dot(vec3d a, vec3d b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
vec3d vec3d_add(vec3d a, vec3d b) {
    return (vec3d){a.x + b.x, a.y + b.y, a.z + b.z};
}
//right handed
vec3d vec3f_cross(vec3d a, vec3d b) {
    vec3d c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}
float vec3i_dot(vec3i a, vec3i b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
vec3i vec3i_add(vec3i a, vec3i b) {
    return (vec3i){a.x + b.x, a.y + b.y, a.z + b.z};
}
//right handed
vec3i vec3i_cross(vec3i a, vec3i b) {
    vec3i c;
    c.x = (a.y * b.z) - (a.z * b.y);
    c.y = (a.z * b.x) - (a.x * b.z);
    c.z = (a.x * b.y) - (a.y * b.x);
    return c;
}


//4D vectors
float vec4f_dot(vec4f a, vec4f b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
vec4f vec4f_add(vec4f a, vec4f b) {
    return (vec4f){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
float vec4d_dot(vec4d a, vec4d b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
vec4d vec4d_add(vec4d a, vec4d b) {
    return (vec4d){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
float vec4i_dot(vec4i a, vec4i b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}
vec4i vec4i_add(vec4i a, vec4i b) {
    return (vec4i){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
