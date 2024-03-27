#include "triangle.h"

// Normal boundary value analysis tests
int main() {
    // Taken from Software Testing, 5th edition Table 5.1
    if ( 1 != triangle_identifier(100, 100,   1)) { return 1; }
    if ( 1 != triangle_identifier(100, 100,   2)) { return 1; }
    if ( 2 != triangle_identifier(100, 100, 100)) { return 1; }
    if ( 1 != triangle_identifier(100, 100, 199)) { return 1; }
    if (-1 != triangle_identifier(100, 100, 200)) { return 1; }

    if ( 1 != triangle_identifier(100,   1, 100)) { return 1; }
    if ( 1 != triangle_identifier(100,   2, 100)) { return 1; }
    if ( 2 != triangle_identifier(100, 100, 100)) { return 1; }
    if ( 1 != triangle_identifier(100, 199, 100)) { return 1; }
    if (-1 != triangle_identifier(100, 200, 100)) { return 1; }

    if ( 1 != triangle_identifier(  1, 100, 100)) { return 1; }
    if ( 1 != triangle_identifier(  2, 100, 100)) { return 1; }
    if ( 2 != triangle_identifier(100, 100, 100)) { return 1; }
    if ( 1 != triangle_identifier(199, 100, 100)) { return 1; }
    if (-1 != triangle_identifier(200, 100, 100)) { return 1; }

    return 0;
}
