#include "triangle.h"

// Weak normal equivalence class tests
// From Software Testing, 5th edition Section 6.4

int main() {
    if ( 2 != triangle_identifier(5, 5, 5)) { return 1; }
    if ( 1 != triangle_identifier(2, 2, 3)) { return 1; }
    if ( 0 != triangle_identifier(3, 4, 5)) { return 1; }
    if (-1 != triangle_identifier(4, 1, 2)) { return 1; }

    return 0;
}
