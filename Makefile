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
II_ARRAY = II_array
III_LINKEDLIST = III_linkedList
IV_STACK = IV_stack
V_QUEUE = V_queue
VI_TREE = VI_tree
VII_BIT_MANIPULATION = VII_bit_manipulation
VIII_CPPCONCEPTUALQUE = VIII_cppConceptualQue

all: I_algorithms 

I_algorithms: I_algorithms_1_maths \
			  I_algorithms_2_binary_search \
			  I_algorithms_3_cyclic_sort \
			  I_algorithms_4_sorting \
			  I_algorithms_5_recursion \
			  I_algorithms_6_two_pointers \
			  I_algorithms_7_sliding_window \
			  I_algorithms_8_fast_slow_pointers \
			  I_algorithms_9_in_place_reversal_linkedlist \
			  II_array \
			  III_linkedList \
			  IV_stack \
			  V_queue \
			  VI_tree \
			  VII_bit_manipulation \
			  VIII_cppConceptualQue


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


II_array:$(II_ARRAY)/2d_array_declaration.o \
		  $(II_ARRAY)/2d_array_string_dma.o \
		  $(II_ARRAY)/array_products.o \
		  $(II_ARRAY)/count_increasing_subarrays.o \
		  $(II_ARRAY)/direction_array.o \
		  $(II_ARRAY)/find_smallest_second_smallest_arr.o \
		  $(II_ARRAY)/get_max_value_last_occurance_2d_arr.o \
		  $(II_ARRAY)/greedy_robot.o \
		  $(II_ARRAY)/grid_unique_paths.o \
		  $(II_ARRAY)/highest_mountain.o \
		  $(II_ARRAY)/largest_subarray_sum.o \
		  $(II_ARRAY)/left_rotate_arr_by_1.o \
		  $(II_ARRAY)/length_longest_substring.o \
		  $(II_ARRAY)/longest_band_whose_reordering_makes_longest_subarray.o \
		  $(II_ARRAY)/maximumSumSubarray.o \
		  $(II_ARRAY)/merge_two_sorted_arr_into_third_sorted_arr.o \
		  $(II_ARRAY)/merge_two_sorted_arrays.o \
		  $(II_ARRAY)/most_frequent_num_arr.o \
		  $(II_ARRAY)/move_zeros_to_end_of_arr.o \
		  $(II_ARRAY)/rains_compute_amt_of_water_trapped.o \
		  $(II_ARRAY)/read_print_2d_arr.o \
		  $(II_ARRAY)/remove_even_ele_arr.o \
		  $(II_ARRAY)/replace_min_max_arr.o \
		  $(II_ARRAY)/rotate_array.o \
		  $(II_ARRAY)/search_ele_array.o \
		  $(II_ARRAY)/smallest_num_rearranging_digit_num.o \
		  $(II_ARRAY)/sort_0_1_2s_arr_75.o \
		  $(II_ARRAY)/sort_array_of_0s_1s.o \
		  $(II_ARRAY)/swap_two_columns_2d_arr.o \
		  $(II_ARRAY)/housing.o \
		  $(II_ARRAY)/insert_element_array.o \
		  $(II_ARRAY)/is_array_sorted.o \
		  $(II_ARRAY)/largest_element_arr.o

$(II_ARRAY)/2d_array_declaration.o: $(II_ARRAY)/2d_array_declaration.c
	gcc $(FLAGS) $(II_ARRAY)/2d_array_declaration $(II_ARRAY)/2d_array_declaration.c

$(II_ARRAY)/2d_array_string_dma.o: $(II_ARRAY)/2d_array_string_dma.cpp
	g++ $(FLAGS) $(II_ARRAY)/2d_array_string_dma $(II_ARRAY)/2d_array_string_dma.cpp
	
$(II_ARRAY)/array_products.o: $(II_ARRAY)/array_products.cpp
	g++ $(FLAGS) $(II_ARRAY)/array_products $(II_ARRAY)/array_products.cpp	
	
$(II_ARRAY)/count_increasing_subarrays.o: $(II_ARRAY)/count_increasing_subarrays.cpp
	g++ $(FLAGS) $(II_ARRAY)/count_increasing_subarrays $(II_ARRAY)/count_increasing_subarrays.cpp	
	
$(II_ARRAY)/direction_array.o: $(II_ARRAY)/direction_array.cpp
	g++ $(FLAGS) $(II_ARRAY)/direction_array $(II_ARRAY)/direction_array.cpp	
	
$(II_ARRAY)/find_smallest_second_smallest_arr.o: $(II_ARRAY)/find_smallest_second_smallest_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/find_smallest_second_smallest_arr $(II_ARRAY)/find_smallest_second_smallest_arr.cpp
	
$(II_ARRAY)/get_max_value_last_occurance_2d_arr.o: $(II_ARRAY)/get_max_value_last_occurance_2d_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/get_max_value_last_occurance_2d_arr $(II_ARRAY)/get_max_value_last_occurance_2d_arr.cpp
	
$(II_ARRAY)/greedy_robot.o: $(II_ARRAY)/greedy_robot.cpp
	g++ $(FLAGS) $(II_ARRAY)/greedy_robot $(II_ARRAY)/greedy_robot.cpp	
	
$(II_ARRAY)/grid_unique_paths.o: $(II_ARRAY)/grid_unique_paths.cpp
	g++ $(FLAGS) $(II_ARRAY)/grid_unique_paths $(II_ARRAY)/grid_unique_paths.cpp
	
$(II_ARRAY)/highest_mountain.o: $(II_ARRAY)/highest_mountain.cpp
	g++ $(FLAGS) $(II_ARRAY)/highest_mountain $(II_ARRAY)/highest_mountain.cpp
	
$(II_ARRAY)/largest_subarray_sum.o: $(II_ARRAY)/largest_subarray_sum.cpp
	g++ $(FLAGS) $(II_ARRAY)/largest_subarray_sum $(II_ARRAY)/largest_subarray_sum.cpp
	
$(II_ARRAY)/left_rotate_arr_by_1.o: $(II_ARRAY)/left_rotate_arr_by_1.cpp
	g++ $(FLAGS) $(II_ARRAY)/left_rotate_arr_by_1 $(II_ARRAY)/left_rotate_arr_by_1.cpp	
	
$(II_ARRAY)/length_longest_substring.o: $(II_ARRAY)/length_longest_substring.cpp
	g++ $(FLAGS) $(II_ARRAY)/length_longest_substring $(II_ARRAY)/length_longest_substring.cpp	
	
$(II_ARRAY)/longest_band_whose_reordering_makes_longest_subarray.o: $(II_ARRAY)/longest_band_whose_reordering_makes_longest_subarray.cpp
	g++ $(FLAGS) $(II_ARRAY)/longest_band_whose_reordering_makes_longest_subarray $(II_ARRAY)/longest_band_whose_reordering_makes_longest_subarray.cpp
	
$(II_ARRAY)/maximumSumSubarray.o: $(II_ARRAY)/maximumSumSubarray.cpp
	g++ $(FLAGS) $(II_ARRAY)/maximumSumSubarray $(II_ARRAY)/maximumSumSubarray.cpp
	
$(II_ARRAY)/merge_two_sorted_arr_into_third_sorted_arr.o: $(II_ARRAY)/merge_two_sorted_arr_into_third_sorted_arr.c
	gcc $(FLAGS) $(II_ARRAY)/merge_two_sorted_arr_into_third_sorted_arr $(II_ARRAY)/merge_two_sorted_arr_into_third_sorted_arr.c
	
$(II_ARRAY)/merge_two_sorted_arrays.o: $(II_ARRAY)/merge_two_sorted_arrays.cpp
	g++ $(FLAGS) $(II_ARRAY)/merge_two_sorted_arrays $(II_ARRAY)/merge_two_sorted_arrays.cpp	
	
$(II_ARRAY)/most_frequent_num_arr.o: $(II_ARRAY)/most_frequent_num_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/most_frequent_num_arr $(II_ARRAY)/most_frequent_num_arr.cpp

$(II_ARRAY)/move_zeros_to_end_of_arr.o: $(II_ARRAY)/move_zeros_to_end_of_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/move_zeros_to_end_of_arr $(II_ARRAY)/move_zeros_to_end_of_arr.cpp

$(II_ARRAY)/rains_compute_amt_of_water_trapped.o: $(II_ARRAY)/rains_compute_amt_of_water_trapped.cpp
	g++ $(FLAGS) $(II_ARRAY)/rains_compute_amt_of_water_trapped $(II_ARRAY)/rains_compute_amt_of_water_trapped.cpp

$(II_ARRAY)/read_print_2d_arr.o: $(II_ARRAY)/read_print_2d_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/read_print_2d_arr $(II_ARRAY)/read_print_2d_arr.cpp

$(II_ARRAY)/remove_even_ele_arr.o: $(II_ARRAY)/remove_even_ele_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/remove_even_ele_arr $(II_ARRAY)/remove_even_ele_arr.cpp

$(II_ARRAY)/replace_min_max_arr.o: $(II_ARRAY)/replace_min_max_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/replace_min_max_arr $(II_ARRAY)/replace_min_max_arr.cpp

$(II_ARRAY)/rotate_array.o: $(II_ARRAY)/rotate_array.cpp
	g++ $(FLAGS) $(II_ARRAY)/rotate_array $(II_ARRAY)/rotate_array.cpp

$(II_ARRAY)/search_ele_array.o: $(II_ARRAY)/search_ele_array.cpp
	g++ $(FLAGS) $(II_ARRAY)/search_ele_array $(II_ARRAY)/search_ele_array.cpp

$(II_ARRAY)/smallest_num_rearranging_digit_num.o: $(II_ARRAY)/smallest_num_rearranging_digit_num.cpp
	g++ $(FLAGS) $(II_ARRAY)/smallest_num_rearranging_digit_num $(II_ARRAY)/smallest_num_rearranging_digit_num.cpp

$(II_ARRAY)/sort_0_1_2s_arr_75.o: $(II_ARRAY)/sort_0_1_2s_arr_75.cpp
	g++ $(FLAGS) $(II_ARRAY)/sort_0_1_2s_arr_75 $(II_ARRAY)/sort_0_1_2s_arr_75.cpp

$(II_ARRAY)/sort_array_of_0s_1s.o: $(II_ARRAY)/sort_array_of_0s_1s.cpp
	g++ $(FLAGS) $(II_ARRAY)/sort_array_of_0s_1s $(II_ARRAY)/sort_array_of_0s_1s.cpp

$(II_ARRAY)/swap_two_columns_2d_arr.o: $(II_ARRAY)/swap_two_columns_2d_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/swap_two_columns_2d_arr $(II_ARRAY)/swap_two_columns_2d_arr.cpp

$(II_ARRAY)/housing.o: $(II_ARRAY)/housing.cpp
	g++ $(FLAGS) $(II_ARRAY)/housing $(II_ARRAY)/housing.cpp

$(II_ARRAY)/insert_element_array.o: $(II_ARRAY)/insert_element_array.cpp
	g++ $(FLAGS) $(II_ARRAY)/insert_element_array $(II_ARRAY)/insert_element_array.cpp

$(II_ARRAY)/is_array_sorted.o: $(II_ARRAY)/is_array_sorted.cpp
	g++ $(FLAGS) $(II_ARRAY)/is_array_sorted $(II_ARRAY)/is_array_sorted.cpp

$(II_ARRAY)/largest_element_arr.o: $(II_ARRAY)/largest_element_arr.cpp
	g++ $(FLAGS) $(II_ARRAY)/largest_element_arr $(II_ARRAY)/largest_element_arr.cpp


III_linkedList:$(III_LINKEDLIST)/convertTheLinkList.o \
			   $(III_LINKEDLIST)/insert_singly_linkedlist.o \
			   $(III_LINKEDLIST)/reverse_singly_linklist.o \
			   $(III_LINKEDLIST)/mergeTwoSortedList.o \
			   $(III_LINKEDLIST)/pairwise_swap_linkedlist.o \
			   $(III_LINKEDLIST)/swap_two_nodes_linkedlist.o \
			   $(III_LINKEDLIST)/delete_node_linkedlist_without_head.o

$(III_LINKEDLIST)/convertTheLinkList.o: $(III_LINKEDLIST)/convertTheLinkList.cpp
	g++ $(FLAGS) $(III_LINKEDLIST)/convertTheLinkList $(III_LINKEDLIST)/convertTheLinkList.cpp

$(III_LINKEDLIST)/insert_singly_linkedlist.o: $(III_LINKEDLIST)/insert_singly_linkedlist.c
	gcc $(FLAGS) $(III_LINKEDLIST)/insert_singly_linkedlist $(III_LINKEDLIST)/insert_singly_linkedlist.c

$(III_LINKEDLIST)/reverse_singly_linklist.o: $(III_LINKEDLIST)/reverse_singly_linklist.cpp
	g++ $(FLAGS) $(III_LINKEDLIST)/reverse_singly_linklist $(III_LINKEDLIST)/reverse_singly_linklist.cpp

$(III_LINKEDLIST)/mergeTwoSortedList.o: $(III_LINKEDLIST)/mergeTwoSortedList.cpp
	g++ $(FLAGS) $(III_LINKEDLIST)/mergeTwoSortedList $(III_LINKEDLIST)/mergeTwoSortedList.cpp

$(III_LINKEDLIST)/pairwise_swap_linkedlist.o: $(III_LINKEDLIST)/pairwise_swap_linkedlist.cpp
	g++ $(FLAGS) $(III_LINKEDLIST)/pairwise_swap_linkedlist $(III_LINKEDLIST)/pairwise_swap_linkedlist.cpp

$(III_LINKEDLIST)/swap_two_nodes_linkedlist.o: $(III_LINKEDLIST)/swap_two_nodes_linkedlist.cpp
	g++ $(FLAGS) $(III_LINKEDLIST)/swap_two_nodes_linkedlist $(III_LINKEDLIST)/swap_two_nodes_linkedlist.cpp

$(III_LINKEDLIST)/delete_node_linkedlist_without_head.o: $(III_LINKEDLIST)/delete_node_linkedlist_without_head.cpp
	g++ $(FLAGS) $(III_LINKEDLIST)/delete_node_linkedlist_without_head $(III_LINKEDLIST)/delete_node_linkedlist_without_head.cpp


IV_stack:$(IV_STACK)/stack_using_array.o \
		 $(IV_STACK)/stack_using_array_simple.o \
		 $(IV_STACK)/stack_using_linkedlist.o \
		 $(IV_STACK)/check_balanced_parantheses.o \
		 $(IV_STACK)/two_stacks_using_single_array.o

$(IV_STACK)/stack_using_array.o: $(IV_STACK)/stack_using_array.c
	gcc $(FLAGS) $(IV_STACK)/stack_using_array $(IV_STACK)/stack_using_array.c

$(IV_STACK)/stack_using_array_simple.o: $(IV_STACK)/stack_using_array_simple.c
	gcc $(FLAGS) $(IV_STACK)/stack_using_array_simple $(IV_STACK)/stack_using_array_simple.c

$(IV_STACK)/stack_using_linkedlist.o: $(IV_STACK)/stack_using_linkedlist.c
	gcc $(FLAGS) $(IV_STACK)/stack_using_linkedlist $(IV_STACK)/stack_using_linkedlist.c

$(IV_STACK)/check_balanced_parantheses.o: $(IV_STACK)/check_balanced_parantheses.cpp
	g++ $(FLAGS) $(IV_STACK)/check_balanced_parantheses $(IV_STACK)/check_balanced_parantheses.cpp

$(IV_STACK)/two_stacks_using_single_array.o: $(IV_STACK)/two_stacks_using_single_array.cpp
	g++ $(FLAGS) $(IV_STACK)/two_stacks_using_single_array $(IV_STACK)/two_stacks_using_single_array.cpp


V_queue:$(V_QUEUE)/queue_using_array_simple.o \
		$(V_QUEUE)/queue_using_list.o

$(V_QUEUE)/queue_using_array_simple.o: $(V_QUEUE)/queue_using_array_simple.cpp
	g++ $(FLAGS) $(V_QUEUE)/queue_using_array_simple $(V_QUEUE)/queue_using_array_simple.cpp

$(V_QUEUE)/queue_using_list.o: $(V_QUEUE)/queue_using_list.cpp
	g++ $(FLAGS) $(V_QUEUE)/queue_using_list $(V_QUEUE)/queue_using_list.cpp


VI_tree:$(VI_TREE)/basicTreeImplementation.o \
		$(VI_TREE)/create_bst.o \
		$(VI_TREE)/count_nodes_bst.o \
		$(VI_TREE)/count_leaf_various_degree_nodes_bst.o \
		$(VI_TREE)/height_bst.o \
		$(VI_TREE)/leftAndRightViewOfBinaryTree.o \
		$(VI_TREE)/search_bst.o \
		$(VI_TREE)/delete_node_bst.o \
		$(VI_TREE)/find_second_largest_element.o

$(VI_TREE)/basicTreeImplementation.o: $(VI_TREE)/basicTreeImplementation.cpp
	g++ $(FLAGS) $(VI_TREE)/basicTreeImplementation $(VI_TREE)/basicTreeImplementation.cpp

$(VI_TREE)/create_bst.o: $(VI_TREE)/create_bst.c
	gcc $(FLAGS) $(VI_TREE)/create_bst $(VI_TREE)/create_bst.c

$(VI_TREE)/count_nodes_bst.o: $(VI_TREE)/count_nodes_bst.c
	gcc $(FLAGS) $(VI_TREE)/count_nodes_bst $(VI_TREE)/count_nodes_bst.c

$(VI_TREE)/count_leaf_various_degree_nodes_bst.o: $(VI_TREE)/count_leaf_various_degree_nodes_bst.c
	gcc $(FLAGS) $(VI_TREE)/count_leaf_various_degree_nodes_bst $(VI_TREE)/count_leaf_various_degree_nodes_bst.c

$(VI_TREE)/height_bst.o: $(VI_TREE)/height_bst.cpp
	g++ $(FLAGS) $(VI_TREE)/height_bst $(VI_TREE)/height_bst.cpp

$(VI_TREE)/leftAndRightViewOfBinaryTree.o: $(VI_TREE)/leftAndRightViewOfBinaryTree.cpp
	g++ $(FLAGS) $(VI_TREE)/leftAndRightViewOfBinaryTree $(VI_TREE)/leftAndRightViewOfBinaryTree.cpp

$(VI_TREE)/search_bst.o: $(VI_TREE)/search_bst.c
	gcc $(FLAGS) $(VI_TREE)/search_bst $(VI_TREE)/search_bst.c

$(VI_TREE)/delete_node_bst.o: $(VI_TREE)/delete_node_bst.c
	gcc $(FLAGS) $(VI_TREE)/delete_node_bst $(VI_TREE)/delete_node_bst.c

$(VI_TREE)/find_second_largest_element.o: $(VI_TREE)/find_second_largest_element.cpp
	g++ $(FLAGS) $(VI_TREE)/find_second_largest_element $(VI_TREE)/find_second_largest_element.cpp


VII_bit_manipulation:$(VII_BIT_MANIPULATION)/base_b_to_decimal_conversion.o \
					 $(VII_BIT_MANIPULATION)/bit_operations.o \
					 $(VII_BIT_MANIPULATION)/bit_swapping.o \
					 $(VII_BIT_MANIPULATION)/check_ith_bit_set.o \
					 $(VII_BIT_MANIPULATION)/clear_2_bits.o \
					 $(VII_BIT_MANIPULATION)/clear_all_even_bits.o \
					 $(VII_BIT_MANIPULATION)/count_set_bits_num.o \
					 $(VII_BIT_MANIPULATION)/decimal_to_base_b_conversion.o \
					 $(VII_BIT_MANIPULATION)/decimal_to_binary.o \
					 $(VII_BIT_MANIPULATION)/endian_conversion.o \
					 $(VII_BIT_MANIPULATION)/find_largest_power_of_2.o \
					 $(VII_BIT_MANIPULATION)/find_position_of_rightmost_set_bit.o \
					 $(VII_BIT_MANIPULATION)/find_unique_ele_in_arr_of_duplicates_with_single_unique_ele.o \
					 $(VII_BIT_MANIPULATION)/is_power_of_2.o \
					 $(VII_BIT_MANIPULATION)/nth_magic_num.o \
					 $(VII_BIT_MANIPULATION)/odd_even.o \
					 $(VII_BIT_MANIPULATION)/set_2_bits.o

$(VII_BIT_MANIPULATION)/base_b_to_decimal_conversion.o: $(VII_BIT_MANIPULATION)/base_b_to_decimal_conversion.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/base_b_to_decimal_conversion $(VII_BIT_MANIPULATION)/base_b_to_decimal_conversion.cpp

$(VII_BIT_MANIPULATION)/bit_operations.o: $(VII_BIT_MANIPULATION)/bit_operations.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/bit_operations $(VII_BIT_MANIPULATION)/bit_operations.cpp

$(VII_BIT_MANIPULATION)/bit_swapping.o: $(VII_BIT_MANIPULATION)/bit_swapping.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/bit_swapping $(VII_BIT_MANIPULATION)/bit_swapping.cpp

$(VII_BIT_MANIPULATION)/check_ith_bit_set.o: $(VII_BIT_MANIPULATION)/check_ith_bit_set.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/check_ith_bit_set $(VII_BIT_MANIPULATION)/check_ith_bit_set.cpp

$(VII_BIT_MANIPULATION)/clear_2_bits.o: $(VII_BIT_MANIPULATION)/clear_2_bits.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/clear_2_bits $(VII_BIT_MANIPULATION)/clear_2_bits.cpp

$(VII_BIT_MANIPULATION)/clear_all_even_bits.o: $(VII_BIT_MANIPULATION)/clear_all_even_bits.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/clear_all_even_bits $(VII_BIT_MANIPULATION)/clear_all_even_bits.cpp

$(VII_BIT_MANIPULATION)/count_set_bits_num.o: $(VII_BIT_MANIPULATION)/count_set_bits_num.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/count_set_bits_num $(VII_BIT_MANIPULATION)/count_set_bits_num.cpp

$(VII_BIT_MANIPULATION)/decimal_to_base_b_conversion.o: $(VII_BIT_MANIPULATION)/decimal_to_base_b_conversion.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/decimal_to_base_b_conversion $(VII_BIT_MANIPULATION)/decimal_to_base_b_conversion.cpp

$(VII_BIT_MANIPULATION)/decimal_to_binary.o: $(VII_BIT_MANIPULATION)/decimal_to_binary.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/decimal_to_binary $(VII_BIT_MANIPULATION)/decimal_to_binary.cpp

$(VII_BIT_MANIPULATION)/endian_conversion.o: $(VII_BIT_MANIPULATION)/endian_conversion.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/endian_conversion $(VII_BIT_MANIPULATION)/endian_conversion.cpp

$(VII_BIT_MANIPULATION)/find_largest_power_of_2.o: $(VII_BIT_MANIPULATION)/find_largest_power_of_2.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/find_largest_power_of_2 $(VII_BIT_MANIPULATION)/find_largest_power_of_2.cpp

$(VII_BIT_MANIPULATION)/find_position_of_rightmost_set_bit.o: $(VII_BIT_MANIPULATION)/find_position_of_rightmost_set_bit.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/find_position_of_rightmost_set_bit $(VII_BIT_MANIPULATION)/find_position_of_rightmost_set_bit.cpp

$(VII_BIT_MANIPULATION)/find_unique_ele_in_arr_of_duplicates_with_single_unique_ele.o: $(VII_BIT_MANIPULATION)/find_unique_ele_in_arr_of_duplicates_with_single_unique_ele.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/find_unique_ele_in_arr_of_duplicates_with_single_unique_ele $(VII_BIT_MANIPULATION)/find_unique_ele_in_arr_of_duplicates_with_single_unique_ele.cpp

$(VII_BIT_MANIPULATION)/is_power_of_2.o: $(VII_BIT_MANIPULATION)/is_power_of_2.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/is_power_of_2 $(VII_BIT_MANIPULATION)/is_power_of_2.cpp

$(VII_BIT_MANIPULATION)/nth_magic_num.o: $(VII_BIT_MANIPULATION)/nth_magic_num.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/nth_magic_num $(VII_BIT_MANIPULATION)/nth_magic_num.cpp

$(VII_BIT_MANIPULATION)/odd_even.o: $(VII_BIT_MANIPULATION)/odd_even.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/odd_even $(VII_BIT_MANIPULATION)/odd_even.cpp

$(VII_BIT_MANIPULATION)/set_2_bits.o: $(VII_BIT_MANIPULATION)/set_2_bits.cpp
	g++ $(FLAGS) $(VII_BIT_MANIPULATION)/set_2_bits $(VII_BIT_MANIPULATION)/set_2_bits.cpp


VIII_cppConceptualQue:$(VIII_CPPCONCEPTUALQUE)/allTypeOfConstructor.o \
					  $(VIII_CPPCONCEPTUALQUE)/longestSubstringWithoutRepeat.o \
					  $(VIII_CPPCONCEPTUALQUE)/singletoneClass.o \
					  $(VIII_CPPCONCEPTUALQUE)/vectorMapSetList.o \
					  $(VIII_CPPCONCEPTUALQUE)/implementStringClass.o \
					  $(VIII_CPPCONCEPTUALQUE)/stackImplementationToConvertNumIntoBinary.o\
					  $(VIII_CPPCONCEPTUALQUE)/mutex.o
					  

$(VIII_CPPCONCEPTUALQUE)/allTypeOfConstructor.o: $(VIII_CPPCONCEPTUALQUE)/allTypeOfConstructor.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/allTypeOfConstructor $(VIII_CPPCONCEPTUALQUE)/allTypeOfConstructor.cpp

$(VIII_CPPCONCEPTUALQUE)/longestSubstringWithoutRepeat.o: $(VIII_CPPCONCEPTUALQUE)/longestSubstringWithoutRepeat.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/longestSubstringWithoutRepeat $(VIII_CPPCONCEPTUALQUE)/longestSubstringWithoutRepeat.cpp

$(VIII_CPPCONCEPTUALQUE)/singletoneClass.o: $(VIII_CPPCONCEPTUALQUE)/singletoneClass.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/singletoneClass $(VIII_CPPCONCEPTUALQUE)/singletoneClass.cpp

$(VIII_CPPCONCEPTUALQUE)/vectorMapSetList.o: $(VIII_CPPCONCEPTUALQUE)/vectorMapSetList.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/vectorMapSetList $(VIII_CPPCONCEPTUALQUE)/vectorMapSetList.cpp

$(VIII_CPPCONCEPTUALQUE)/implementStringClass.o: $(VIII_CPPCONCEPTUALQUE)/implementStringClass.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/implementStringClass $(VIII_CPPCONCEPTUALQUE)/implementStringClass.cpp

$(VIII_CPPCONCEPTUALQUE)/implementStringClass.o: $(VIII_CPPCONCEPTUALQUE)/implementStringClass.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/implementStringClass $(VIII_CPPCONCEPTUALQUE)/stackImplementationToConvertNumIntoBinary.cpp

$(VIII_CPPCONCEPTUALQUE)/smartPointer.o: $(VIII_CPPCONCEPTUALQUE)/smartPointer.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/smartPointer $(VIII_CPPCONCEPTUALQUE)/smartPointer.cpp

$(VIII_CPPCONCEPTUALQUE)/mutex.o: $(VIII_CPPCONCEPTUALQUE)/mutex.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/mutex $(VIII_CPPCONCEPTUALQUE)/mutex.cpp

$(VIII_CPPCONCEPTUALQUE)/rotateLinkList.o: $(VIII_CPPCONCEPTUALQUE)/rotateLinkList.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/rotateLinkList $(VIII_CPPCONCEPTUALQUE)/rotateLinkList.cpp

$(VIII_CPPCONCEPTUALQUE)/minOperation.o: $(VIII_CPPCONCEPTUALQUE)/minOperation.cpp
	g++ $(FLAGS) $(VIII_CPPCONCEPTUALQUE)/minOperation $(VIII_CPPCONCEPTUALQUE)/minOperation.cpp
clean:
	rm -f $(I_ALGORITHMS_1_MATHS)/factors_of_num.exe
	rm -f $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.exe
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
	rm -f $(II_ARRAY)/2d_array_declaration
	rm -f $(II_ARRAY)/2d_array_string_dma
	rm -f $(II_ARRAY)/array_products
	rm -f $(II_ARRAY)/count_increasing_subarrays
	rm -f $(II_ARRAY)/direction_array
	rm -f $(II_ARRAY)/find_smallest_second_smallest_arr
	rm -f $(II_ARRAY)/get_max_value_last_occurance_2d_arr
	rm -f $(II_ARRAY)/greedy_robot
	rm -f $(II_ARRAY)/grid_unique_paths
	rm -f $(II_ARRAY)/highest_mountain
	rm -f $(II_ARRAY)/largest_subarray_sum
	rm -f $(II_ARRAY)/left_rotate_arr_by_1
	rm -f $(II_ARRAY)/length_longest_substring
	rm -f $(II_ARRAY)/longest_band_whose_reordering_makes_longest_subarray
	rm -f $(II_ARRAY)/maximumSumSubarray
	rm -f $(II_ARRAY)/merge_two_sorted_arr_into_third_sorted_arr
	rm -f $(II_ARRAY)/merge_two_sorted_arrays
	rm -f $(II_ARRAY)/most_frequent_num_arr
	rm -f $(II_ARRAY)/move_zeros_to_end_of_arr
	rm -f $(II_ARRAY)/rains_compute_amt_of_water_trapped
	rm -f $(II_ARRAY)/read_print_2d_arr
	rm -f $(II_ARRAY)/remove_even_ele_arr
	rm -f $(II_ARRAY)/replace_min_max_arr
	rm -f $(II_ARRAY)/rotate_array
	rm -f $(II_ARRAY)/search_ele_array
	rm -f $(II_ARRAY)/smallest_num_rearranging_digit_num
	rm -f $(II_ARRAY)/sort_0_1_2s_arr_75
	rm -f $(II_ARRAY)/sort_array_of_0s_1s
	rm -f $(II_ARRAY)/swap_two_columns_2d_arr
	rm -f $(II_ARRAY)/housing
	rm -f $(II_ARRAY)/insert_element_array
	rm -f $(II_ARRAY)/is_array_sorted
	rm -f $(II_ARRAY)/largest_element_arr
	rm -f $(III_LINKEDLIST)/convertTheLinkList
	rm -f $(III_LINKEDLIST)/insert_singly_linkedlist
	rm -f $(III_LINKEDLIST)/reverse_singly_linklist
	rm -f $(III_LINKEDLIST)/mergeTwoSortedList
	rm -f $(III_LINKEDLIST)/pairwise_swap_linkedlist
	rm -f $(III_LINKEDLIST)/swap_two_nodes_linkedlist
	rm -f $(III_LINKEDLIST)/delete_node_linkedlist_without_head
	rm -f $(IV_STACK)/stack_using_array
	rm -f $(IV_STACK)/stack_using_array_simple
	rm -f $(IV_STACK)/stack_using_linkedlist
	rm -f $(IV_STACK)/check_balanced_parantheses
	rm -f $(IV_STACK)/two_stacks_using_single_array
	rm -f $(V_QUEUE)/queue_using_array_simple
	rm -f $(V_QUEUE)/queue_using_list
	rm -f $(VI_TREE)/basicTreeImplementation
	rm -f $(VI_TREE)/create_bst
	rm -f $(VI_TREE)/count_nodes_bst
	rm -f $(VI_TREE)/count_leaf_various_degree_nodes_bst
	rm -f $(VI_TREE)/height_bst
	rm -f $(VI_TREE)/leftAndRightViewOfBinaryTree
	rm -f $(VI_TREE)/search_bst
	rm -f $(VI_TREE)/delete_node_bst
	rm -f $(VI_TREE)/find_second_largest_element
	rm -f $(VII_BIT_MANIPULATION)/base_b_to_decimal_conversion
	rm -f $(VII_BIT_MANIPULATION)/bit_operations
	rm -f $(VII_BIT_MANIPULATION)/bit_swapping
	rm -f $(VII_BIT_MANIPULATION)/check_ith_bit_set
	rm -f $(VII_BIT_MANIPULATION)/clear_2_bits
	rm -f $(VII_BIT_MANIPULATION)/clear_all_even_bits
	rm -f $(VII_BIT_MANIPULATION)/count_set_bits_num
	rm -f $(VII_BIT_MANIPULATION)/decimal_to_base_b_conversion
	rm -f $(VII_BIT_MANIPULATION)/decimal_to_binary
	rm -f $(VII_BIT_MANIPULATION)/endian_conversion
	rm -f $(VII_BIT_MANIPULATION)/find_largest_power_of_2
	rm -f $(VII_BIT_MANIPULATION)/find_position_of_rightmost_set_bit
	rm -f $(VII_BIT_MANIPULATION)/find_unique_ele_in_arr_of_duplicates_with_single_unique_ele
	rm -f $(VII_BIT_MANIPULATION)/is_power_of_2
	rm -f $(VII_BIT_MANIPULATION)/nth_magic_num
	rm -f $(VII_BIT_MANIPULATION)/odd_even
	rm -f $(VII_BIT_MANIPULATION)/set_2_bits
	rm -f $(VIII_CPPCONCEPTUALQUE)/allTypeOfConstructor
	rm -f $(VIII_CPPCONCEPTUALQUE)/longestSubstringWithoutRepeat
	rm -f $(VIII_CPPCONCEPTUALQUE)/singletoneClass
	rm -f $(VIII_CPPCONCEPTUALQUE)/vectorMapSetList
	rm -f $(VIII_CPPCONCEPTUALQUE)/stackImplementationToConvertNumIntoBinary
	rm -r $(VIII_CPPCONCEPTUALQUE)/smartPointer
	rm -r $(VIII_CPPCONCEPTUALQUE)/implementStringClass
	rm -r $(VIII_CPPCONCEPTUALQUE)/mutex
	

