#include "matrices.h"

//note about matrix indicies
//[x][y]
/*
   y
x    -->
   |  [0][0]   [1][0]   [2][0] ...
   V  [0][1]   [1][1]   [2][1]
      [0][2]   [1][2]   [2][2]
      .                        .
      .                          .
      .
*/




//2x2--------------------------------------------------------------------------------------------
vec2f util_math_matrix2x2_vec2_multf(matrix2x2f* m, vec2f* v) {
    vec2f out;
    out.x = (v->x * m->components[0][0]) + (v->y * m->components[1][0]);
    out.y = (v->x * m->components[0][1]) + (v->y * m->components[1][1]);
    return out;
}
matrix2x2f util_math_matrix2x2_compf(matrix2x2f* m1, matrix2x2f* m2) {
    matrix2x2f out;
    out.components[0][0] = (m1->components[0][0] * m2->components[0][0]) +
                           (m1->components[1][0] * m2->components[0][1]);

    out.components[0][1] = (m1->components[0][1] * m2->components[0][0]) +
                           (m1->components[1][1] * m2->components[0][1]);

    out.components[1][0] = (m1->components[0][0] * m2->components[1][0]) +
                           (m1->components[1][0] * m2->components[1][1]);

    out.components[0][1] = (m1->components[0][1] * m2->components[1][0]) +
                           (m1->components[1][1] * m2->components[1][1]);
    return out;
}
float util_math_matrix2x2_detf(matrix2x2f* m) {
    return (m->components[0][0] * m->components[1][1]) - (m->components[0][1] * m->components[1][0]);
}

vec2d util_math_matrix2x2_vec2_multd(matrix2x2d* m, vec2d* v) {
    vec2d out;
    out.x = (v->x * m->components[0][0]) + (v->y * m->components[1][0]);
    out.y = (v->x * m->components[0][1]) + (v->y * m->components[1][1]);
    return out;
}
matrix2x2d util_math_matrix2x2_compd(matrix2x2d* m1, matrix2x2d* m2) {
    matrix2x2d out;
    out.components[0][0] = (m1->components[0][0] * m2->components[0][0]) +
                           (m1->components[1][0] * m2->components[0][1]);

    out.components[0][1] = (m1->components[0][1] * m2->components[0][0]) +
                           (m1->components[1][1] * m2->components[0][1]);

    out.components[1][0] = (m1->components[0][0] * m2->components[1][0]) +
                           (m1->components[1][0] * m2->components[1][1]);

    out.components[0][1] = (m1->components[0][1] * m2->components[1][0]) +
                           (m1->components[1][1] * m2->components[1][1]);
    return out;
}
double util_math_matrix2x2_detd(matrix2x2d* m) {
    return (m->components[0][0] * m->components[1][1]) - (m->components[0][1] * m->components[1][0]);
}


vec2i util_math_matrix2x2_vec2_multi(matrix2x2i* m, vec2i* v) {
    vec2i out;
    out.x = (v->x * m->components[0][0]) + (v->y * m->components[1][0]);
    out.y = (v->x * m->components[0][1]) + (v->y * m->components[1][1]);
    return out;
}
matrix2x2i util_math_matrix2x2_compi(matrix2x2i* m1, matrix2x2i* m2) {
    matrix2x2i out;
    out.components[0][0] = (m1->components[0][0] * m2->components[0][0]) +
                           (m1->components[1][0] * m2->components[0][1]);

    out.components[0][1] = (m1->components[0][1] * m2->components[0][0]) +
                           (m1->components[1][1] * m2->components[0][1]);

    out.components[1][0] = (m1->components[0][0] * m2->components[1][0]) +
                           (m1->components[1][0] * m2->components[1][1]);

    out.components[0][1] = (m1->components[0][1] * m2->components[1][0]) +
                           (m1->components[1][1] * m2->components[1][1]);
    return out;
}
int util_math_matrix2x2_deti(matrix2x2i* m) {
    return (m->components[0][0] * m->components[1][1]) - (m->components[0][1] * m->components[1][0]);
}



//3x3 -------------------------------------------------------------------------------------------
vec3f util_math_matrix3x3_vec3_multf(matrix3x3f* m, vec3f* v) {
    vec3f out;
    out.x = (m->components[0][0] * v->x) + (m->components[1][0] * v->y) + (m->components[2][0] * v->z);
    out.y = (m->components[0][1] * v->x) + (m->components[1][1] * v->y) + (m->components[2][1] * v->z);
    out.z = (m->components[0][2] * v->x) + (m->components[1][2] * v->y) + (m->components[2][2] * v->z);
    return out;
}
matrix3x3f util_math_matrix3x3_compf(matrix3x3f* m1, matrix3x3f* m2) {
    vec3f c1 = util_math_matrix3x3_vec3_multf(m1, (vec3f*)m2->components[0]);
    vec3f c2 = util_math_matrix3x3_vec3_multf(m1, (vec3f*)m2->components[1]);
    vec3f c3 = util_math_matrix3x3_vec3_multf(m1, (vec3f*)m2->components[2]);
    return (matrix3x3f){{{c1.x, c1.y, c1.z},
                         {c2.x, c2.y, c2.z},
                         {c3.x, c3.y, c3.z}}};
}
float util_math_matrix3x3_detf(matrix3x3f* m) {
    float positive = m->components[0][0] * m->components[1][1] * m->components[2][2];
    positive += m->components[1][0] * m->components[2][1] * m->components[0][2];
    positive += m->components[2][0] * m->components[0][1] * m->components[1][2];

    float negative = m->components[0][2] * m->components[1][1] * m->components[2][0];
    negative += m->components[1][2] * m->components[2][1] * m->components[0][0];
    negative += m->components[2][2] * m->components[0][1] * m->components[1][0];

    return positive - negative;
}

vec3d util_math_matrix3x3_vec3_multd(matrix3x3d* m, vec3d* v) {
    vec3d out;
    out.x = (m->components[0][0] * v->x) + (m->components[1][0] * v->y) + (m->components[2][0] * v->z);
    out.y = (m->components[0][1] * v->x) + (m->components[1][1] * v->y) + (m->components[2][1] * v->z);
    out.z = (m->components[0][2] * v->x) + (m->components[1][2] * v->y) + (m->components[2][2] * v->z);
    return out;
}
matrix3x3d util_math_matrix3x3_compd(matrix3x3d* m1, matrix3x3d* m2) {
    vec3d c1 = util_math_matrix3x3_vec3_multd(m1, (vec3d*)m2->components[0]);
    vec3d c2 = util_math_matrix3x3_vec3_multd(m1, (vec3d*)m2->components[1]);
    vec3d c3 = util_math_matrix3x3_vec3_multd(m1, (vec3d*)m2->components[2]);
    return (matrix3x3d){{{c1.x, c1.y, c1.z},
                        {c2.x, c2.y, c2.z},
                        {c3.x, c3.y, c3.z}}};
}
double util_math_matrix3x3_detd(matrix3x3d* m) {
    float positive = m->components[0][0] * m->components[1][1] * m->components[2][2];
    positive += m->components[1][0] * m->components[2][1] * m->components[0][2];
    positive += m->components[2][0] * m->components[0][1] * m->components[1][2];

    float negative = m->components[0][2] * m->components[1][1] * m->components[2][0];
    negative += m->components[1][2] * m->components[2][1] * m->components[0][0];
    negative += m->components[2][2] * m->components[0][1] * m->components[1][0];

    return positive - negative;
}

vec3i util_math_matrix3x3_vec3_multi(matrix3x3i* m, vec3i* v) {
    vec3i out;
    out.x = (m->components[0][0] * v->x) + (m->components[1][0] * v->y) + (m->components[2][0] * v->z);
    out.y = (m->components[0][1] * v->x) + (m->components[1][1] * v->y) + (m->components[2][1] * v->z);
    out.z = (m->components[0][2] * v->x) + (m->components[1][2] * v->y) + (m->components[2][2] * v->z);
    return out;
}
matrix3x3i util_math_matrix3x3_compi(matrix3x3i* m1, matrix3x3i* m2) {
    vec3i c1 = util_math_matrix3x3_vec3_multi(m1, (vec3i*)m2->components[0]);
    vec3i c2 = util_math_matrix3x3_vec3_multi(m1, (vec3i*)m2->components[1]);
    vec3i c3 = util_math_matrix3x3_vec3_multi(m1, (vec3i*)m2->components[2]);
    return (matrix3x3i){{{c1.x, c1.y, c1.z},
                        {c2.x, c2.y, c2.z},
                        {c3.x, c3.y, c3.z}}};
}
int util_math_matrix3x3_deti(matrix3x3i* m) {
    float positive = m->components[0][0] * m->components[1][1] * m->components[2][2];
    positive += m->components[1][0] * m->components[2][1] * m->components[0][2];
    positive += m->components[2][0] * m->components[0][1] * m->components[1][2];

    float negative = m->components[0][2] * m->components[1][1] * m->components[2][0];
    negative += m->components[1][2] * m->components[2][1] * m->components[0][0];
    negative += m->components[2][2] * m->components[0][1] * m->components[1][0];

    return positive - negative;
}


//4x4 --------------------------------------------------------------------------------------------
vec4f util_math_matrix4x4_vec4_multf(matrix4x4f* m, vec4f* v) {
    vec4f out;
    out.x = (m->components[0][0] * v->x) + (m->components[1][0] * v->y) + (m->components[2][0] * v->z) + (m->components[3][0] * v->w);
    out.y = (m->components[0][1] * v->x) + (m->components[1][1] * v->y) + (m->components[2][1] * v->z) + (m->components[3][1] * v->w);
    out.z = (m->components[0][2] * v->x) + (m->components[1][2] * v->y) + (m->components[2][2] * v->z) + (m->components[3][2] * v->w);
    out.w = (m->components[0][3] * v->x) + (m->components[1][3] * v->y) + (m->components[2][3] * v->z) + (m->components[3][3] * v->w);
    return out;
}
matrix4x4f util_math_matrix4x4_compf(matrix4x4f* m1, matrix4x4f* m2) {
    vec4f c1 = util_math_matrix4x4_vec4_multf(m1, (vec4f*)m2->components[0]);
    vec4f c2 = util_math_matrix4x4_vec4_multf(m1, (vec4f*)m2->components[1]);
    vec4f c3 = util_math_matrix4x4_vec4_multf(m1, (vec4f*)m2->components[2]);
    vec4f c4 = util_math_matrix4x4_vec4_multf(m1, (vec4f*)m2->components[3]);
    return (matrix4x4f){{
        {c1.x, c1.y, c1.z, c1.w},
        {c2.x, c2.y, c2.z, c2.w},
        {c3.x, c3.y, c3.z, c3.w},
        {c4.x, c4.y, c4.z, c4.w}}};
}
float util_math_matrix4x4_detf(matrix4x4f* m) {
    matrix3x3f a = {{
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3f b = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3f c = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3f d = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]}
    }};

    return (
            (m->components[0][0] * util_math_matrix3x3_detf(&a)) - 
            (m->components[1][0] * util_math_matrix3x3_detf(&b)) +
            (m->components[2][0] * util_math_matrix3x3_detf(&c)) -
            (m->components[3][0] * util_math_matrix3x3_detf(&d)));
}

vec4d util_math_matrix4x4_vec4_multd(matrix4x4d* m, vec4d* v) {
    vec4d out;
    out.x = (m->components[0][0] * v->x) + (m->components[1][0] * v->y) + (m->components[2][0] * v->z) + (m->components[3][0] * v->w);
    out.y = (m->components[0][1] * v->x) + (m->components[1][1] * v->y) + (m->components[2][1] * v->z) + (m->components[3][1] * v->w);
    out.z = (m->components[0][2] * v->x) + (m->components[1][2] * v->y) + (m->components[2][2] * v->z) + (m->components[3][2] * v->w);
    out.w = (m->components[0][3] * v->x) + (m->components[1][3] * v->y) + (m->components[2][3] * v->z) + (m->components[3][3] * v->w);
    return out;
}
matrix4x4d matrix4x4_compd(matrix4x4d* m1, matrix4x4d* m2) {
    vec4d c1 = util_math_matrix4x4_vec4_multd(m1, (vec4d*)m2->components[0]);
    vec4d c2 = util_math_matrix4x4_vec4_multd(m1, (vec4d*)m2->components[1]);
    vec4d c3 = util_math_matrix4x4_vec4_multd(m1, (vec4d*)m2->components[2]);
    vec4d c4 = util_math_matrix4x4_vec4_multd(m1, (vec4d*)m2->components[3]);
    return (matrix4x4d){{
        {c1.x, c1.y, c1.z, c1.w},
        {c2.x, c2.y, c2.z, c2.w},
        {c3.x, c3.y, c3.z, c3.w},
        {c4.x, c4.y, c4.z, c4.w}}};
}
double util_math_matrix4x4_detd(matrix4x4d* m) {
    matrix3x3d a = {{
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3d b = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3d c = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3d d = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]}
    }};

    return (
            (m->components[0][0] * util_math_matrix3x3_detd(&a)) - 
            (m->components[1][0] * util_math_matrix3x3_detd(&b)) +
            (m->components[2][0] * util_math_matrix3x3_detd(&c)) -
            (m->components[3][0] * util_math_matrix3x3_detd(&d)));
}

vec4i util_math_matrix4x4_vec4_multi(matrix4x4i* m, vec4i* v) {
    vec4i out;
    out.x = (m->components[0][0] * v->x) + (m->components[1][0] * v->y) + (m->components[2][0] * v->z) + (m->components[3][0] * v->w);
    out.y = (m->components[0][1] * v->x) + (m->components[1][1] * v->y) + (m->components[2][1] * v->z) + (m->components[3][1] * v->w);
    out.z = (m->components[0][2] * v->x) + (m->components[1][2] * v->y) + (m->components[2][2] * v->z) + (m->components[3][2] * v->w);
    out.w = (m->components[0][3] * v->x) + (m->components[1][3] * v->y) + (m->components[2][3] * v->z) + (m->components[3][3] * v->w);
    return out;
}
matrix4x4i util_math_matrix4x4_compi(matrix4x4i* m1, matrix4x4i* m2) {
    vec4i c1 = util_math_matrix4x4_vec4_multi(m1, (vec4i*)m2->components[0]);
    vec4i c2 = util_math_matrix4x4_vec4_multi(m1, (vec4i*)m2->components[1]);
    vec4i c3 = util_math_matrix4x4_vec4_multi(m1, (vec4i*)m2->components[2]);
    vec4i c4 = util_math_matrix4x4_vec4_multi(m1, (vec4i*)m2->components[3]);
    return (matrix4x4i){{
        {c1.x, c1.y, c1.z, c1.w},
        {c2.x, c2.y, c2.z, c2.w},
        {c3.x, c3.y, c3.z, c3.w},
        {c4.x, c4.y, c4.z, c4.w}}};
}
int util_math_matrix4x4_deti(matrix4x4i* m) {
    matrix3x3i a = {{
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3i b = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3i c = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[3][1], m->components[3][2], m->components[3][3]}
    }};
    matrix3x3i d = {{
        {m->components[0][1], m->components[0][2], m->components[0][3]},
        {m->components[1][1], m->components[1][2], m->components[1][3]},
        {m->components[2][1], m->components[2][2], m->components[2][3]}
    }};

    return (
            (m->components[0][0] * util_math_matrix3x3_deti(&a)) - 
            (m->components[1][0] * util_math_matrix3x3_deti(&b)) +
            (m->components[2][0] * util_math_matrix3x3_deti(&c)) -
            (m->components[3][0] * util_math_matrix3x3_deti(&d)));
}

//nxn ---------------------------------------------------------------------------------------------

//out vector must be preallocated
enum matrix_Error util_math_matrixNxN_vecN_multf(vector_n_f* out, matrixNxNf* m, vector_n_f* v) {
    if (out->size != v->size || m->size[0] != v->size) {
        return IncompatibleSizes;
    }

    vector_n_f temp = {m->size[0], 0};
    for (int i = 0; i < m->size[1]; i++) {
        temp.components = &(m->components[i]);
        util_math_vecNf_dot(&out->components[i], v, &temp);
    }
    
    return NoError;
}
//Out matrix must be preallocated
//Note: if A is L x M
//      if B is M x N
//         C must be L x N
enum matrix_Error util_math_matrixNxN_compf(matrixNxNf* out, matrixNxNf* m1, matrixNxNf* m2) {
    if (m1->size[0]  != m2->size[1] || 
        out->size[0] != m2->size[0] || 
        out->size[1] != m1->size[1]) {

        return IncompatibleSizes;
    }


    vector_n_f temp1 = {m2->size[1], 0};
    vector_n_f temp2 = {m2->size[1], 0};
    for (int i = 0; i < m2->size[0]; i++) {
        temp1.components = &m2->components[i];
        temp2.components = &out->components[i];
        util_math_matrixNxN_vecN_multf(&temp2, m1, &temp1);
    }

    return NoError;
}

/*
not right now -> in future plan to use either LU decomposition
or possibly row echelon conversion to calculate for arbitrary matrix
However I don't think this is necessary so I'm gonna move on.
enum matrix_Error util_math_matrixNxN_detf(float* out, matrixNxNf* m) {
    return NotImplemented;
}
*/



//out vector must be preallocated
enum matrix_Error util_math_matrixNxN_vecN_multd(vector_n_d* out, matrixNxNd* m, vector_n_d* v) {
    if (out->size != v->size || m->size[0] != v->size) {
        return IncompatibleSizes;
    }

    vector_n_d temp = {m->size[0], 0};
    for (int i = 0; i < m->size[1]; i++) {
        temp.components = &(m->components[i]);
        util_math_vecNd_dot(&out->components[i], v, &temp);
    }
    
    return NoError;
}
//Out matrix must be preallocated
//Note: if A is L x M
//      if B is M x N
//         C must be L x N
enum matrix_Error util_math_matrixNxN_compd(matrixNxNd* out, matrixNxNd* m1, matrixNxNd* m2) {
    if (m1->size[0]  != m2->size[1] || 
        out->size[0] != m2->size[0] || 
        out->size[1] != m1->size[1]) {

        return IncompatibleSizes;
    }


    vector_n_d temp1 = {m2->size[1], 0};
    vector_n_d temp2 = {m2->size[1], 0};
    for (int i = 0; i < m2->size[0]; i++) {
        temp1.components = &m2->components[i];
        temp2.components = &out->components[i];
        util_math_matrixNxN_vecN_multd(&temp2, m1, &temp1);
    }

    return NoError;
}

/*
not right now -> in future plan to use either LU decomposition
or possibly row echelon conversion to calculate for arbitrary matrix
However I don't think this is necessary so I'm gonna move on.
enum matrix_Error util_math_matrixNxN_detd(double* out, matrixNxNd* m) {
    return NotImplemented;
}
*/



//out vector must be preallocated
enum matrix_Error util_math_matrixNxN_vecN_multi(vector_n_i* out, matrixNxNi* m, vector_n_i* v) {
    if (out->size != v->size || m->size[0] != v->size) {
        return IncompatibleSizes;
    }

    vector_n_i temp = {m->size[0], 0};
    for (int i = 0; i < m->size[1]; i++) {
        temp.components = &(m->components[i]);
        util_math_vecNi_dot(&out->components[i], v, &temp);
    }
    
    return NoError;
}
//Out matrix must be preallocated
//Note: if A is L x M
//      if B is M x N
//         C must be L x N
enum matrix_Error util_math_matrixNxN_compi(matrixNxNi* out, matrixNxNi* m1, matrixNxNi* m2) {
    if (m1->size[0]  != m2->size[1] || 
        out->size[0] != m2->size[0] || 
        out->size[1] != m1->size[1]) {

        return IncompatibleSizes;
    }


    vector_n_i temp1 = {m2->size[1], 0};
    vector_n_i temp2 = {m2->size[1], 0};
    for (int i = 0; i < m2->size[0]; i++) {
        temp1.components = &m2->components[i];
        temp2.components = &out->components[i];
        util_math_matrixNxN_vecN_multi(&temp2, m1, &temp1);
    }

    return NoError;
}

/*
not right now -> in future plan to use either LU decomposition
or possibly row echelon conversion to calculate for arbitrary matrix
However I don't think this is necessary so I'm gonna move on.
enum matrix_Error matrixNxN_deti(int* out, matrixNxNi* m) {
    return NotImplemented;
}
*/


