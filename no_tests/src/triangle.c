#include <stdio.h>

#include "triangle.h"

int triangle_identifier(int a, int b, int c) {
    int is_a_triangle = 0;

    // Is a triangle?
    if (a < b+c && b < a+c && c < a+b) {
        is_a_triangle = 1;
    }

    enum type triangle_type = INVALID;
    if (is_a_triangle) {
        if (a == b && b == c) {
            triangle_type = EQUILATERAL;
        } else if (a != b && a != c && b != c) {
            triangle_type = SCALENE;
        } else {
            triangle_type = ISOSCELES;
        }
    }

    return triangle_type;
}
