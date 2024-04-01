#include "unity.h"
#include "triangle.h"

// Decision-table based tests
// Taken from Software Testing, 5th edition Table 7.11 (impossible tests not included)

void setUp(void) {
}

void tearDown(void) {
}

void test_decision_table(void) {
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(4, 1, 2));
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(1, 4, 2));
    TEST_ASSERT_EQUAL_INT(-1, triangle_identifier(1, 2, 4));
    TEST_ASSERT_EQUAL_INT( 2, triangle_identifier(5, 5, 5));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(2, 2, 3));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(2, 3, 2));
    TEST_ASSERT_EQUAL_INT( 1, triangle_identifier(3, 2, 2));
    TEST_ASSERT_EQUAL_INT( 0, triangle_identifier(3, 4, 5));

}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_decision_table);
    return UNITY_END();
}
