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
            DAY_02/q8_palindrome_number.c
            DAY_03/q9_check_prime.c
            DAY_03/q10_prime_range.c
            DAY_03/q11_find_gcd.c
            DAY_03/q12_find_lcm.c
            DAY_04/q13_fibonacci_series.c
            DAY_04/q14_nth_fibonacci.c
            DAY_04/q15_check_armstrong.c
            DAY_04/q16_armstrong_range.c
            DAY_05/q17_check_perfect.c
            DAY_05/q18_check_strong.c
            DAY_05/q19_print_factors.c
            DAY_05/q20_largest_prime_factor.c
            DAY_06/q21_decimal_to_binary.c
            DAY_06/q22_binary_to_decimal.c
            DAY_06/q23_count_set_bits.c
            DAY_06/q24_power_without_pow.c
            DAY_07/q25_recursive_factorial.c
            DAY_07/q26_recursive_fibonacci.c
            DAY_07/q27_recursive_sum_digits.c
            DAY_07/q28_recursive_reverse.c
            DAY_08/q29_half_pyramid.c
            DAY_08/q30_number_triangle.c
            DAY_08/q31_character_triangle.c
            DAY_08/q32_repeated_number_pattern.c
            DAY_09/q33_reverse_star.c
            DAY_09/q34_reverse_number_triangle.c
            DAY_09/q35_repeated_char_pattern.c
            DAY_09/q36_hollow_square.c
            DAY_10/q37_star_pyramid.c
            DAY_10/q38_reverse_pyramid.c
            DAY_10/q39_number_pyramid.c
            DAY_10/q40_character_pyramid.c)
endforeach()