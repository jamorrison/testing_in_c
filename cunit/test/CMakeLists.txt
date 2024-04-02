project(Test)

# Build triangle executable
add_executable(test_triangle test_triangle.c)

target_link_libraries(test_triangle core ${CMAKE_CURRENT_SOURCE_DIR}/../CUnit/CUnit/Sources/.libs/libcunit.a)

target_include_directories(test_triangle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../CUnit/CUnit/Headers)

add_test(NAME test_triangle COMMAND test_triangle)
