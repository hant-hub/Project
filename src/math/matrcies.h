#ifndef MATRICIES_H
#define MATRICIES_H

#include "../util/Error.h"
#include "vector.h"

//later possible use for inverting/arbitrary composition
enum matrix_Error {
    IncompatibleSizes = NoError + 1,
    NonSquareMatrix,
    UnInvertableMatrix
};

//2x2-----------------------------------------------------------------------
typedef struct matrix2x2f {
    float components[2][2];
} matrix2x2f;

vec2f matrix2x2_vec2_multf(matrix2x2f* m, vec2f* v);
matrix2x2f matrix2x2_compf(matrix2x2f* m1, matrix2x2f* m2);
float matrix2x2_detf(matrix2x2f* m);

typedef struct matrix2x2d {
    double components[2][2];
} matrix2x2d;

vec2d matrix2x2_vec2_multd(matrix2x2d* m, vec2d* v);
matrix2x2d matrix2x2_compd(matrix2x2d* m1, matrix2x2d* m2);
double matrix2x2_detd(matrix2x2d* m);

typedef struct matrix2x2i {
    int components[2][2];
} matrix2x2i;

vec2i matrix2x2_vec2_multi(matrix2x2i* m, vec2i* v);
matrix2x2i matrix2x2_compi(matrix2x2i* m1, matrix2x2i* m2);
int matrix2x2_deti(matrix2x2i* m);


//3x3--------------------------------------------------------------------------

typedef struct matrix3x3f {
    float components[3][3];
} matrix3x3f;

vec3f matrix3x3_vec3_multf(matrix3x3f* m, vec3f* v);
matrix3x3f matrix3x3_compf(matrix3x3f* m1, matrix3x3f* m2);
float matrix3x3_detf(matrix3x3f* m);

typedef struct matrix3x3d {
    double components[3][3];
} matrix3x3d;

vec3d matrix3x3_vec3_multd(matrix3x3d* m, vec3d* v);
matrix3x3d matrix3x3_compd(matrix3x3d* m1, matrix3x3d* m2);
double matrix3x3_detd(matrix3x3d* m);

typedef struct matrix3x3i {
    int components[3][3];
} matrix3x3i;

vec3i matrix3x3_vec3_multi(matrix3x3i* m, vec3i* v);
matrix3x3i matrix3x3_compi(matrix3x3i* m1, matrix3x3i* m2);
int matrix3x3_deti(matrix3x3i* m);

//4x4--------------------------------------------------------------------------
typedef struct matrix4x4f {
    float components[4][4];
} matrix4x4f;

vec4f matrix4x4_vec4_multf(matrix4x4f* m, vec4f* v);
matrix4x4f matrix4x4_compf(matrix4x4f* m1, matrix4x4f* m2);
float matrix4x4_detf(matrix4x4f* m);

typedef struct matrix4x4d {
    double components[4][4];
} matrix4x4d;

vec4d matrix4x4_vec4_multd(matrix4x4d* m, vec4d* v);
matrix4x4d matrix4x4_compd(matrix4x4d* m1, matrix4x4d* m2);
double matrix4x4_detd(matrix4x4d* m);

typedef struct matrix4x4i {
    int components[4][4];
} matrix4x4i;

vec4i matrix4x4_vec4_multi(matrix4x4i* m, vec4i* v);
matrix4x4i matrix4x4_compi(matrix4x4i* m1, matrix4x4i* m2);
int matrix4x4_deti(matrix4x4i* m);



//nxn
typedef struct matrixNxNf {
    unsigned short size[2];
    float* components;
} matrixNxNf;

enum matrix_Error matrixNxN_vecN_multf(vector_n_f* out, matrixNxNf* m, vector_n_f* v);
enum matrix_Error matrixNxN_compf(matrixNxNf* out, matrixNxNf* m1, matrixNxNf* m2);
enum matrix_Error matrixNxN_detf(float* out, matrixNxNf* m);

typedef struct matrixNxNd {
    unsigned short size[2];
    double* components;
} matrixNxNd;

enum matrix_Error matrixNxN_vecN_multd(vector_n_d* out, matrixNxNd* m, vector_n_d* v);
enum matrix_Error matrixNxN_compd(matrixNxNd* out, matrixNxNd* m1, matrixNxNd* m2);
enum matrix_Error matrixNxN_detd(double* out, matrixNxNd* m);

typedef struct matrixNxNi {
    unsigned short size[2];
    int* components;
} matrixNxNi;

enum matrix_Error matrixNxN_vecN_multi(vector_n_i* out, matrixNxNi* m, vector_n_i* v);
enum matrix_Error matrixNxN_compi(matrixNxNi* out, matrixNxNi* m1, matrixNxNi* m2);
enum matrix_Error matrixNxN_deti(int* out, matrixNxNi* m);

#endif