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

static inline void print_type(int res, int a, int b, int c) {
    switch (res) {
        case -1:
            fprintf(
                stdout,
                "Triangle <%i, %i, %i> is an INVALID triangle\n",
                a, b, c
            );
            break;
        case 0:
            fprintf(
                stdout,
                "Triangle <%i, %i, %i> is a SCALENE triangle\n",
                a, b, c
            );
            break;
        case 1:
            fprintf(
                stdout,
                "Triangle <%i, %i, %i> is an ISOSCELES triangle\n",
                a, b, c
            );
            break;
        case 2:
            fprintf(
                stdout,
                "Triangle <%i, %i, %i> is an EQUILATERAL triangle\n",
                a, b, c
            );
            break;
        default:
            fprintf(
                stdout,
                "Unknown result returned: %i\n",
                res
            );
            break;
    }
}

int main() {
    int res = triangle_identifier(3, 4, 5);
    print_type(res, 3, 4, 5);

    res = triangle_identifier(4, 2, 2);
    print_type(res, 4, 2, 2);

    return 0;
}
