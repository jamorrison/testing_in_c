project(Test)


# Build triangle executable
add_executable(test_triangle test_triangle.c)
add_test(NAME test_triangle COMMAND test_triangle)

add_executable(test_boundary_value test_boundary_value.c)
add_test(NAME test_boundary_value COMMAND test_boundary_value)

add_executable(test_equivalence test_equivalence.c)
add_test(NAME test_equivalence COMMAND test_equivalence)

add_executable(test_decision_table test_decision_table.c)
add_test(NAME test_decision_table COMMAND test_decision_table)

target_link_libraries(test_triangle core)
target_link_libraries(test_boundary_value core)
target_link_libraries(test_equivalence core)
target_link_libraries(test_decision_table core)
