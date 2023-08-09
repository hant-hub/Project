#include "matrcies.h"


vec2f matrix2x2_vec2_multf(matrix2x2f* m, vec2f* v) {
    vec2f out;
    out.x = (v->x * m->components[0][0]) + (v->y * m->components[1][0]);
    out.y = (v->x * m->components[0][1]) + (v->y * m->components[1][1]);
    return out;
}
matrix2x2f matrix2x2_compf(matrix2x2f* m1, matrix2x2f* m2) {
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
float matrix2x2_detf(matrix2x2f* m) {
    return (m->components[0][0] * m->components[1][1]) - (m->components[0][1] * m->components[1][0]);
}