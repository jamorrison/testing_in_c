#include "unity.h"
#include "triangle.h"

// Weak normal equivalence class tests
// From Software Testing, 5th edition Section 6.4

void setUp(void) {
}

void tearDown(void) {
}

void test_equivalence(void) {
    TEST_ASSERT_EQUAL_INT( 2, triangle_identifier(5, 5, 5));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(2, 2, 3));
    TEST_ASSERT_EQUAL_INT( 0, triangle_identifier(3, 4, 5));
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(4, 1, 2));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_equivalence);
    return UNITY_END();
}
