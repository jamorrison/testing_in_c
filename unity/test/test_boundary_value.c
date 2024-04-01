#include "unity.h"
#include "triangle.h"

// Normal boundary value analysis tests
// Taken from Software Testing, 5th edition Table 5.1

void setUp(void) {
}

void tearDown(void) {
}

void test_boundary_a(void) {
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(  1, 100, 100));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(  2, 100, 100));
    TEST_ASSERT_EQUAL_INT( 2, triangle_identifier(100, 100, 100));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(199, 100, 100));
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(200, 100, 100));
}

void test_boundary_b(void) {
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(100,   1, 100));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(100,   2, 100));
    TEST_ASSERT_EQUAL_INT( 2, triangle_identifier(100, 100, 100));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(100, 199, 100));
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(100, 200, 100));
}

void test_boundary_c(void) {
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(100, 100,   1));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(100, 100,   2));
    TEST_ASSERT_EQUAL_INT( 2, triangle_identifier(100, 100, 100));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(100, 100, 199));
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(100, 100, 200));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_boundary_a);
    RUN_TEST(test_boundary_b);
    RUN_TEST(test_boundary_c);
    return UNITY_END();
}
