#include "unity.h"
#include "triangle.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_scalene(void) {
    TEST_ASSERT_EQUAL_INT(0, triangle_identifier(3, 4, 5));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_scalene);
    return UNITY_END();
}
