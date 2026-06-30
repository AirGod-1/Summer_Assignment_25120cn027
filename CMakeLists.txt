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
            DAY_10/q40_character_pyramid.c
            DAY_11/q41_function_sum.c
            DAY_11/q42_function_maximum.c
            DAY_11/q43_function_prime.c
            DAY_11/q44_function_factorial.c
            DAY_12/q45_function_palindrome.c
            DAY_12/q46_function_armstrong.c
            DAY_12/q47_function_fibonacci.c
            DAY_12/q48_function_perfect.c
            DAY_13/q49_input_display_array.c
            DAY_13/q50_sum_average_array.c
            DAY_13/q51_largest_smallest_element.c
            DAY_13/q52_count_even_odd.c
            DAY_14/q53_linear_search.c
            DAY_14/q54_frequency_element.c
            DAY_14/q55_second_largest.c
            DAY_14/q56_find_duplicates.c
            DAY_15/q57_reverse_array.c
            DAY_15/q58_rotate_left.c
            DAY_15/q59_rotate_right.c
            DAY_15/q60_move_zeroes_end.c
            DAY_16/q61_missing_number.c
            DAY_16/q62_max_frequency_element.c
            DAY_16/q63_pair_given_sum.c
            DAY_16/q64_remove_duplicates.c
            DAY_17/q65_merge_arrays.c
            DAY_17/q66_union_arrays.c
            DAY_17/q67_intersection_arrays.c
            DAY_17/q68_common_elements.c
            DAY_18/q69_bubble_sort.c
            DAY_18/q70_selection_sort.c
            DAY_18/q71_binary_search.c
            DAY_18/q72_sort_descending.c
            DAY_19/q73_add_matrices.c
            DAY_19/q74_subtract_matrices.c
            DAY_19/q75_transpose_matrix.c
            DAY_19/q76_diagonal_sum.c
            DAY_20/q77_multiply_matrices.c
            DAY_20/q78_check_symmetric.c
            DAY_20/q79_row_wise_sum.c
            DAY_20/q80_column_wise_sum.c
            DAY_21/q81_string_length.c
            DAY_21/q82_reverse_string.c
            DAY_21/q83_count_vowels_consonants.c
            DAY_21/q84_lower_to_upper.c
            DAY_22/q85_palindrome_string.c
            DAY_22/q86_count_words.c
            DAY_22/q87_character_frequency.c
            DAY_22/q88_remove_spaces.c
            DAY_23/q89_first_non_repeating.c
            DAY_23/q90_first_repeating.c
            DAY_23/q91_check_anagram.c
            DAY_23/q92_max_occurring_char.c
            DAY_24/q93_check_string_rotation.c
            DAY_24/q94_compress_string.c
            DAY_24/q95_longest_word.c
            DAY_24/q96_remove_duplicate_chars.c
            DAY_25/q97_merge_sorted_arrays.c
            DAY_25/q98_common_characters.c
            DAY_25/q99_sort_names_alphabetically.c
            DAY_25/q100_sort_words_length.c
            DAY_26/q101_number_guessing_game.c
            DAY_26/q102_voting_eligibility.c
            DAY_26/q103_atm_simulation.c
            DAY_26/q104_quiz_application.c
            DAY_27/q105_student_record_sys.c
            DAY_27/q106_employee_management_sys.c
            DAY_27/q107_salary_management_sys.c
            DAY_27/q108_marksheet_generation.c
            DAY_28/q109_library_management.c
            DAY_28/q110_bank_account_sys.c
            DAY_28/q111_ticket_booking_sys.c
            DAY_28/q112_contact_management.c)
endforeach()