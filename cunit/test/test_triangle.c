#include <stdlib.h>
#include "Basic.h"
#include "CUnit.h"
#include "triangle.h"

static int suite_init(void) {
    return 0;
}

static int suite_cleanup(void) {
    return 0;
}

static void test_scalene(void) {
    CU_ASSERT(0 == triangle_identifier(3, 4, 5));
}

static void test_failure(void) {
    CU_ASSERT(1 == triangle_identifier(3, 4, 5));
}

static void test_boundary_a(void) {
    CU_ASSERT( 1 == triangle_identifier(  1, 100, 100));
    CU_ASSERT( 1 == triangle_identifier(  2, 100, 100));
    CU_ASSERT( 2 == triangle_identifier(100, 100, 100));
    CU_ASSERT( 1 == triangle_identifier(199, 100, 100));
    CU_ASSERT(-1 == triangle_identifier(200, 100, 100));
}

static void test_boundary_b(void) {
    CU_ASSERT( 1 == triangle_identifier(100,   1, 100));
    CU_ASSERT( 1 == triangle_identifier(100,   2, 100));
    CU_ASSERT( 2 == triangle_identifier(100, 100, 100));
    CU_ASSERT( 1 == triangle_identifier(100, 199, 100));
    CU_ASSERT(-1 == triangle_identifier(100, 200, 100));
}

static void test_boundary_c(void) {
    CU_ASSERT( 1 == triangle_identifier(100, 100,   1));
    CU_ASSERT( 1 == triangle_identifier(100, 100,   2));
    CU_ASSERT( 2 == triangle_identifier(100, 100, 100));
    CU_ASSERT( 1 == triangle_identifier(100, 100, 199));
    CU_ASSERT(-1 == triangle_identifier(100, 100, 200));
}

static void test_decision_table(void) {
    CU_ASSERT(-1 == triangle_identifier(4, 1, 2));
    CU_ASSERT(-1 == triangle_identifier(1, 4, 2));
    CU_ASSERT(-1 == triangle_identifier(1, 2, 4));
    CU_ASSERT( 2 == triangle_identifier(5, 5, 5));
    CU_ASSERT( 1 == triangle_identifier(2, 2, 3));
    CU_ASSERT( 1 == triangle_identifier(2, 3, 2));
    CU_ASSERT( 1 == triangle_identifier(3, 2, 2));
    CU_ASSERT( 0 == triangle_identifier(3, 4, 5));
}

static void test_equivalence(void) {
    CU_ASSERT( 2 == triangle_identifier(5, 5, 5));
    CU_ASSERT( 1 == triangle_identifier(2, 2, 3));
    CU_ASSERT( 0 == triangle_identifier(3, 4, 5));
    CU_ASSERT(-1 == triangle_identifier(4, 1, 2));
}

static CU_TestInfo tests_general[] = {
    { "test_scalene", test_scalene },
    { "test_failure", test_failure },
    CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_boundary_value[] = {
    { "test_boundary_value_a", test_boundary_a },
    { "test_boundary_value_b", test_boundary_b },
    { "test_boundary_value_c", test_boundary_c },
    CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_decision_table_based[] = {
    { "test_decision_table", test_decision_table },
    CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_equivalence[] = {
    { "test_equivalence", test_equivalence },
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
    { "suite_general"       , suite_init, suite_cleanup, NULL, NULL, tests_general},
    { "suite_boundary_value", suite_init, suite_cleanup, NULL, NULL, tests_boundary_value},
    { "suite_decision_table", suite_init, suite_cleanup, NULL, NULL, tests_decision_table_based},
    { "suite_equivalence"   , suite_init, suite_cleanup, NULL, NULL, tests_equivalence},
    CU_SUITE_INFO_NULL,
};

int main() {
    CU_BasicRunMode mode = CU_BRM_VERBOSE;
    CU_ErrorAction error_action = CUEA_IGNORE;

    if (CU_initialize_registry()) {
        printf("\nInitialization of test registry failed.");
    } else {
        if (CU_register_suites(suites) != CUE_SUCCESS) {
            fprintf(stderr, "suite registration failed - %s\n", CU_get_error_msg());
            exit(EXIT_FAILURE);
        }
        CU_basic_set_mode(mode);
        CU_set_error_action(error_action);
        printf("\nTesting completed with return value %d.\n", CU_basic_run_tests());
        CU_cleanup_registry();
    }

    return 0;
}
