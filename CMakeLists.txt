cmake_minimum_required(VERSION 3.20)
project(Summer_Assignment_25120cn027 C)

set(CMAKE_C_STANDARD 99)

# This automatically finds every .c file in your DAY_ folders
file(GLOB_RECURSE SOURCES "DAY_*/*.c")

# This loop turns every .c file into its own runnable program
foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE}
            DAY_01/q2_multiplication_table.c
            DAY_01/q3_factorial.c
            DAY_01/q4_count_digits.c
            DAY_02/q5_sum_of_digits.c
            DAY_02/q6_reverse_number.c
            DAY_02/q7_product_of_digits.c
            DAY_02/q8_palindrome_number.c)
endforeach()