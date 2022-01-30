FLAGS = -g -o
I_ALGORITHMS_1_MATHS = I_algorithms/1_maths
I_ALGORITHMS_2_BINARY_SEARCH = I_algorithms/2_binary_search
I_ALGORITHMS_3_CYCLIC_SORT = I_algorithms/3_cyclic_sort
I_ALGORITHMS_4_SORTING = I_algorithms/4_sorting
I_ALGORITHMS_5_RECURSION = I_algorithms/5_recursion
I_ALGORITHMS_6_TWO_POINTERS = I_algorithms/6_two_pointers
I_ALGORITHMS_7_SLIDING_WINDOW = I_algorithms/7_sliding_window
I_ALGORITHMS_8_FAST_SLOW_POINTERS = I_algorithms/8_fast_slow_pointers
I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST = I_algorithms/9_in_place_reversal_linkedlist


all: I_algorithms 

I_algorithms: I_algorithms_1_maths \
			  I_algorithms_2_binary_search \
			  I_algorithms_3_cyclic_sort \
			  I_algorithms_4_sorting \
			  I_algorithms_5_recursion \
			  I_algorithms_6_two_pointers \
			  I_algorithms_7_sliding_window \
			  I_algorithms_8_fast_slow_pointers \
			  I_algorithms_9_in_place_reversal_linkedlist


I_algorithms_1_maths: $(I_ALGORITHMS_1_MATHS)/factors_of_num.o \
					  $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.o \
					  $(I_ALGORITHMS_1_MATHS)/is_prime.o \
					  $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.o \
					  $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.o

$(I_ALGORITHMS_1_MATHS)/factors_of_num.o: $(I_ALGORITHMS_1_MATHS)/factors_of_num.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/factors_of_num $(I_ALGORITHMS_1_MATHS)/factors_of_num.cpp

$(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.o: $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.cpp

$(I_ALGORITHMS_1_MATHS)/is_prime.o: $(I_ALGORITHMS_1_MATHS)/is_prime.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/is_prime $(I_ALGORITHMS_1_MATHS)/is_prime.cpp
	
$(I_ALGORITHMS_1_MATHS)/print_prime_numbers.o: $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/print_prime_numbers $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.cpp
	
$(I_ALGORITHMS_1_MATHS)/sqrt_of_num.o: $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/sqrt_of_num $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.cpp


I_algorithms_2_binary_search: $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.o \
							  $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.o

$(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.cpp
	
$(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.cpp


I_algorithms_3_cyclic_sort: $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.o \

$(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.cpp


I_algorithms_4_sorting:$(I_ALGORITHMS_4_SORTING)/bubble_sort.o \
					   $(I_ALGORITHMS_4_SORTING)/insertion_sort.o \
					   $(I_ALGORITHMS_4_SORTING)/merge_sort.o 
					   

$(I_ALGORITHMS_4_SORTING)/bubble_sort.o: $(I_ALGORITHMS_4_SORTING)/bubble_sort.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_4_SORTING)/bubble_sort $(I_ALGORITHMS_4_SORTING)/bubble_sort.cpp

$(I_ALGORITHMS_4_SORTING)/insertion_sort.o: $(I_ALGORITHMS_4_SORTING)/insertion_sort.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_4_SORTING)/insertion_sort $(I_ALGORITHMS_4_SORTING)/insertion_sort.cpp

$(I_ALGORITHMS_4_SORTING)/merge_sort.o: $(I_ALGORITHMS_4_SORTING)/merge_sort.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_4_SORTING)/merge_sort $(I_ALGORITHMS_4_SORTING)/merge_sort.cpp


I_algorithms_5_recursion:$(I_ALGORITHMS_5_RECURSION)/count_number_of_zeros_in_num.o \
					     $(I_ALGORITHMS_5_RECURSION)/factorial.o \
					     $(I_ALGORITHMS_5_RECURSION)/generate_all_subsets_subsequences.o \
					     $(I_ALGORITHMS_5_RECURSION)/letter_combination_phone_number.o \
					     $(I_ALGORITHMS_5_RECURSION)/maze_problem_counting_paths.o \
					     $(I_ALGORITHMS_5_RECURSION)/palindrome_number.o \
					     $(I_ALGORITHMS_5_RECURSION)/reverse_number.o \
					     $(I_ALGORITHMS_5_RECURSION)/skip_a_char_string.o \
					     $(I_ALGORITHMS_5_RECURSION)/sum_of_digits.o 

$(I_ALGORITHMS_5_RECURSION)/count_number_of_zeros_in_num.o: $(I_ALGORITHMS_5_RECURSION)/count_number_of_zeros_in_num.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/count_number_of_zeros_in_num $(I_ALGORITHMS_5_RECURSION)/count_number_of_zeros_in_num.cpp

$(I_ALGORITHMS_5_RECURSION)/factorial.o: $(I_ALGORITHMS_5_RECURSION)/factorial.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/factorial $(I_ALGORITHMS_5_RECURSION)/factorial.cpp
	
$(I_ALGORITHMS_5_RECURSION)/generate_all_subsets_subsequences.o: $(I_ALGORITHMS_5_RECURSION)/generate_all_subsets_subsequences.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/generate_all_subsets_subsequences $(I_ALGORITHMS_5_RECURSION)/generate_all_subsets_subsequences.cpp
	
$(I_ALGORITHMS_5_RECURSION)/letter_combination_phone_number.o: $(I_ALGORITHMS_5_RECURSION)/letter_combination_phone_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/letter_combination_phone_number $(I_ALGORITHMS_5_RECURSION)/letter_combination_phone_number.cpp

$(I_ALGORITHMS_5_RECURSION)/maze_problem_counting_paths.o: $(I_ALGORITHMS_5_RECURSION)/maze_problem_counting_paths.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/maze_problem_counting_paths $(I_ALGORITHMS_5_RECURSION)/maze_problem_counting_paths.cpp	

$(I_ALGORITHMS_5_RECURSION)/palindrome_number.o: $(I_ALGORITHMS_5_RECURSION)/palindrome_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/palindrome_number $(I_ALGORITHMS_5_RECURSION)/palindrome_number.cpp

$(I_ALGORITHMS_5_RECURSION)/reverse_number.o: $(I_ALGORITHMS_5_RECURSION)/reverse_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/reverse_number $(I_ALGORITHMS_5_RECURSION)/reverse_number.cpp

$(I_ALGORITHMS_5_RECURSION)/skip_a_char_string.o: $(I_ALGORITHMS_5_RECURSION)/skip_a_char_string.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/skip_a_char_string $(I_ALGORITHMS_5_RECURSION)/skip_a_char_string.cpp

$(I_ALGORITHMS_5_RECURSION)/sum_of_digits.o: $(I_ALGORITHMS_5_RECURSION)/sum_of_digits.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_5_RECURSION)/sum_of_digits $(I_ALGORITHMS_5_RECURSION)/sum_of_digits.cpp	


I_algorithms_6_two_pointers:$(I_ALGORITHMS_6_TWO_POINTERS)/pair_sum_in_sorted_arr.o \
							$(I_ALGORITHMS_6_TWO_POINTERS)/square_ele_sorted_arr.o \
							$(I_ALGORITHMS_6_TWO_POINTERS)/dutch_national_flag.o \
							$(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_duplicates.o \
							$(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_elements_of_key.o \
							$(I_ALGORITHMS_6_TWO_POINTERS)/triplet_sum_close_to_target.o \
							$(I_ALGORITHMS_6_TWO_POINTERS)/unique_triplets_sum_equal_0.o

$(I_ALGORITHMS_6_TWO_POINTERS)/pair_sum_in_sorted_arr.o: $(I_ALGORITHMS_6_TWO_POINTERS)/pair_sum_in_sorted_arr.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/pair_sum_in_sorted_arr $(I_ALGORITHMS_6_TWO_POINTERS)/pair_sum_in_sorted_arr.cpp

$(I_ALGORITHMS_6_TWO_POINTERS)/square_ele_sorted_arr.o: $(I_ALGORITHMS_6_TWO_POINTERS)/square_ele_sorted_arr.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/square_ele_sorted_arr $(I_ALGORITHMS_6_TWO_POINTERS)/square_ele_sorted_arr.cpp
	
$(I_ALGORITHMS_6_TWO_POINTERS)/dutch_national_flag.o: $(I_ALGORITHMS_6_TWO_POINTERS)/dutch_national_flag.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/dutch_national_flag $(I_ALGORITHMS_6_TWO_POINTERS)/dutch_national_flag.cpp	

$(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_duplicates.o: $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_duplicates.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_duplicates $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_duplicates.cpp

$(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_elements_of_key.o: $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_elements_of_key.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_elements_of_key $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_elements_of_key.cpp

$(I_ALGORITHMS_6_TWO_POINTERS)/triplet_sum_close_to_target.o: $(I_ALGORITHMS_6_TWO_POINTERS)/triplet_sum_close_to_target.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/triplet_sum_close_to_target $(I_ALGORITHMS_6_TWO_POINTERS)/triplet_sum_close_to_target.cpp

$(I_ALGORITHMS_6_TWO_POINTERS)/unique_triplets_sum_equal_0.o: $(I_ALGORITHMS_6_TWO_POINTERS)/unique_triplets_sum_equal_0.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_6_TWO_POINTERS)/unique_triplets_sum_equal_0 $(I_ALGORITHMS_6_TWO_POINTERS)/unique_triplets_sum_equal_0.cpp


I_algorithms_7_sliding_window:$(I_ALGORITHMS_7_SLIDING_WINDOW)/find_all_subarray_avg.o \
					   $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_max_sum_subarray_of_size_k.o \
					   $(I_ALGORITHMS_7_SLIDING_WINDOW)/largest_substr_with_k_distinct_chars.o \
					   $(I_ALGORITHMS_7_SLIDING_WINDOW)/smallest_subarray_with_given_sum.o
					   

$(I_ALGORITHMS_7_SLIDING_WINDOW)/find_all_subarray_avg.o: $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_all_subarray_avg.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_all_subarray_avg $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_all_subarray_avg.cpp

$(I_ALGORITHMS_7_SLIDING_WINDOW)/find_max_sum_subarray_of_size_k.o: $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_max_sum_subarray_of_size_k.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_max_sum_subarray_of_size_k $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_max_sum_subarray_of_size_k.cpp

$(I_ALGORITHMS_7_SLIDING_WINDOW)/largest_substr_with_k_distinct_chars.o: $(I_ALGORITHMS_7_SLIDING_WINDOW)/largest_substr_with_k_distinct_chars.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_7_SLIDING_WINDOW)/largest_substr_with_k_distinct_chars $(I_ALGORITHMS_7_SLIDING_WINDOW)/largest_substr_with_k_distinct_chars.cpp

$(I_ALGORITHMS_7_SLIDING_WINDOW)/smallest_subarray_with_given_sum.o: $(I_ALGORITHMS_7_SLIDING_WINDOW)/smallest_subarray_with_given_sum.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_7_SLIDING_WINDOW)/smallest_subarray_with_given_sum $(I_ALGORITHMS_7_SLIDING_WINDOW)/smallest_subarray_with_given_sum.cpp


I_algorithms_8_fast_slow_pointers:$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_middle_of_linkedlist.o \
								  $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_in_linkedlist.o \
								  $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_length_in_linkedlist.o \
								  $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_start_of_cycle_linkedlist.o \
								  $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/check_linkedlist_palindrome.o \
								  $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/happy_number.o

$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_middle_of_linkedlist.o: $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_middle_of_linkedlist.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_middle_of_linkedlist $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_middle_of_linkedlist.cpp

$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_in_linkedlist.o: $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_in_linkedlist.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_in_linkedlist $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_in_linkedlist.cpp

$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_length_in_linkedlist.o: $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_length_in_linkedlist.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_length_in_linkedlist $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_length_in_linkedlist.cpp

$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_start_of_cycle_linkedlist.o: $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_start_of_cycle_linkedlist.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_start_of_cycle_linkedlist $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_start_of_cycle_linkedlist.cpp

$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/check_linkedlist_palindrome.o: $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/check_linkedlist_palindrome.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/check_linkedlist_palindrome $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/check_linkedlist_palindrome.cpp

$(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/happy_number.o: $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/happy_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/happy_number $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/happy_number.cpp


I_algorithms_9_in_place_reversal_linkedlist:$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_linkedlist.o \
											$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_sub_list.o \
											$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_k_element_sub_list.o \
											$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_first_k_ele.o \
											$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_list_based_on_size.o \
											$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_alternate_k_element_sublist.o \
											$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/rotate_linkedlist_k_size.o

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_linkedlist.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_linkedlist.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_linkedlist $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_linkedlist.cpp

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_sub_list.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_sub_list.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_sub_list $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_sub_list.cpp

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_k_element_sub_list.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_k_element_sub_list.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_k_element_sub_list $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_k_element_sub_list.cpp

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_first_k_ele.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_first_k_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_first_k_ele $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_first_k_ele.cpp

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_list_based_on_size.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_list_based_on_size.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_list_based_on_size $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_list_based_on_size.cpp

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_alternate_k_element_sublist.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_alternate_k_element_sublist.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_alternate_k_element_sublist $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_alternate_k_element_sublist.cpp

$(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/rotate_linkedlist_k_size.o: $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/rotate_linkedlist_k_size.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/rotate_linkedlist_k_size $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/rotate_linkedlist_k_size.cpp


clean:
	rm -f $(I_ALGORITHMS_1_MATHS)/factors_of_num
	rm -f $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums
	rm -f $(I_ALGORITHMS_1_MATHS)/is_prime
	rm -f $(I_ALGORITHMS_1_MATHS)/print_prime_numbers
	rm -f $(I_ALGORITHMS_1_MATHS)/factors_of_num
	rm -f $(I_ALGORITHMS_1_MATHS)/sqrt_of_num
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele
	rm -f $(I_ALGORITHMS_4_SORTING)/bubble_sort
	rm -f $(I_ALGORITHMS_4_SORTING)/insertion_sort
	rm -f $(I_ALGORITHMS_4_SORTING)/merge_sort
	rm -f $(I_ALGORITHMS_5_RECURSION)/count_number_of_zeros_in_num
	rm -f $(I_ALGORITHMS_5_RECURSION)/factorial
	rm -f $(I_ALGORITHMS_5_RECURSION)/generate_all_subsets_subsequences
	rm -f $(I_ALGORITHMS_5_RECURSION)/letter_combination_phone_number
	rm -f $(I_ALGORITHMS_5_RECURSION)/maze_problem_counting_paths
	rm -f $(I_ALGORITHMS_5_RECURSION)/palindrome_number
	rm -f $(I_ALGORITHMS_5_RECURSION)/reverse_number
	rm -f $(I_ALGORITHMS_5_RECURSION)/skip_a_char_string
	rm -f $(I_ALGORITHMS_5_RECURSION)/sum_of_digits
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/pair_sum_in_sorted_arr
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/square_ele_sorted_arr
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/dutch_national_flag
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_duplicates
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/remove_all_elements_of_key
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/triplet_sum_close_to_target
	rm -f $(I_ALGORITHMS_6_TWO_POINTERS)/unique_triplets_sum_equal_0
	rm -f $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_all_subarray_avg
	rm -f $(I_ALGORITHMS_7_SLIDING_WINDOW)/find_max_sum_subarray_of_size_k
	rm -f $(I_ALGORITHMS_7_SLIDING_WINDOW)/largest_substr_with_k_distinct_chars
	rm -f $(I_ALGORITHMS_7_SLIDING_WINDOW)/smallest_subarray_with_given_sum
	rm -f $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_middle_of_linkedlist
	rm -f $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_in_linkedlist
	rm -f $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_cycle_length_in_linkedlist
	rm -f $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/find_start_of_cycle_linkedlist
	rm -f $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/check_linkedlist_palindrome
	rm -f $(I_ALGORITHMS_8_FAST_SLOW_POINTERS)/happy_number
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_linkedlist
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_sub_list
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_k_element_sub_list
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_first_k_ele
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_list_based_on_size
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/reverse_every_alternate_k_element_sublist
	rm -f $(I_ALGORITHMS_9_IN_PLACE_REVERSAL_LINKEDLIST)/rotate_linkedlist_k_size
