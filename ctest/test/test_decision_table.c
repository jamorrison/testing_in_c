#include "triangle.h"

// Decision-table based tests
// Taken from Software Testing, 5th edition Table 7.11 (impossible tests not included)

int main() {
    if (-1 != triangle_identifier(4, 1, 2)) { return 1; }
    if (-1 != triangle_identifier(1, 4, 2)) { return 1; }
    if (-1 != triangle_identifier(1, 2, 4)) { return 1; }
    if ( 2 != triangle_identifier(5, 5, 5)) { return 1; }
    if ( 1 != triangle_identifier(2, 2, 3)) { return 1; }
    if ( 1 != triangle_identifier(2, 3, 2)) { return 1; }
    if ( 1 != triangle_identifier(3, 2, 2)) { return 1; }
    if ( 0 != triangle_identifier(3, 4, 5)) { return 1; }

    return 0;
}
