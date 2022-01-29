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

I_algorithms: I_algorithms_1_maths I_algorithms_2_binary_search I_algorithms_3_cyclic_sort I_algorithms_4_sorting

I_algorithms_1_maths: $(I_ALGORITHMS_1_MATHS)/factors_of_num.o \
					  $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.o \
					  $(I_ALGORITHMS_1_MATHS)/is_prime.o \
					  $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.o \
					  $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.o

$(I_ALGORITHMS_1_MATHS)/factors_of_num.o: $(I_ALGORITHMS_1_MATHS)/factors_of_num.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/factors_of_num.o $(I_ALGORITHMS_1_MATHS)/factors_of_num.cpp

$(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.o: $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.o $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.cpp

$(I_ALGORITHMS_1_MATHS)/is_prime.o: $(I_ALGORITHMS_1_MATHS)/is_prime.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/is_prime.o $(I_ALGORITHMS_1_MATHS)/is_prime.cpp
	
$(I_ALGORITHMS_1_MATHS)/print_prime_numbers.o: $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.o $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.cpp
	
$(I_ALGORITHMS_1_MATHS)/sqrt_of_num.o: $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.o $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.cpp


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
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.o $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.o $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.cpp
	
$(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.o $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.o $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.o $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.o $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.o $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.o $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.cpp

$(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.o: $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.o $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.cpp

I_algorithms_3_cyclic_sort: $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.o \
							$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.o \

$(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.o $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.o $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.o $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.o $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.cpp

$(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.o: $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.o $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.cpp


I_algorithms_4_sorting:$(I_ALGORITHMS_4_SORTING)/bubble_sort.o \
					   $(I_ALGORITHMS_4_SORTING)/insertion_sort.o \
					   $(I_ALGORITHMS_4_SORTING)/merge_sort.o 
					   

$(I_ALGORITHMS_4_SORTING)/bubble_sort.o: $(I_ALGORITHMS_4_SORTING)/bubble_sort.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_4_SORTING)/bubble_sort.o $(I_ALGORITHMS_4_SORTING)/bubble_sort.cpp

$(I_ALGORITHMS_4_SORTING)/insertion_sort.o: $(I_ALGORITHMS_4_SORTING)/insertion_sort.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_4_SORTING)/insertion_sort.o $(I_ALGORITHMS_4_SORTING)/insertion_sort.cpp

$(I_ALGORITHMS_4_SORTING)/merge_sort.o: $(I_ALGORITHMS_4_SORTING)/merge_sort.cpp
	g++ $(FLAGS) $(I_ALGORITHMS_4_SORTING)/merge_sort.o $(I_ALGORITHMS_4_SORTING)/merge_sort.cpp



clean:
	rm -f $(I_ALGORITHMS_1_MATHS)/factors_of_num.o
	rm -f $(I_ALGORITHMS_1_MATHS)/gcd_lcm_of_two_nums.o
	rm -f $(I_ALGORITHMS_1_MATHS)/is_prime.o
	rm -f $(I_ALGORITHMS_1_MATHS)/print_prime_numbers.o
	rm -f $(I_ALGORITHMS_1_MATHS)/factors_of_num.o
	rm -f $(I_ALGORITHMS_1_MATHS)/sqrt_of_num.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/binary_search.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/ceiling_of_number.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/find_first_last_pos_sorted.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/find_in_mountain_array.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/find_pos_of_ele_infinite_arr.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/floor_of_number.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/order_agnostic_search.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/peak_index_mountain_array.o
	rm -f $(I_ALGORITHMS_2_BINARY_SEARCH)/search_in_rotated_sorted_arr.o
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/cyclic_sort_implementation.o
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_duplicate_ele.o
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_all_missing_elements.o
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_duplicate_ele.o
	rm -f $(I_ALGORITHMS_3_CYCLIC_SORT)/find_single_missing_ele.o
	rm -f $(I_ALGORITHMS_4_SORTING)/bubble_sort.o
	rm -f $(I_ALGORITHMS_4_SORTING)/insertion_sort.o
	rm -f $(I_ALGORITHMS_4_SORTING)/merge_sort.o