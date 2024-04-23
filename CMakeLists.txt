cmake_minimum_required(VERSION 3.16)
project(Standard_DSA_Library_for_c C)

set(CMAKE_C_STANDARD 99)

add_executable(Standard_DSA_Library_for_C 

	test_code/test_code1.c

	algorithms/sorting/sorting.c
	algorithms/numeric_algorithms/numeric_algos.c
	data_structures/deque/deque.c
	data_structures/queue/queue.c
	data_structures/stack/vector_stack.c
	data_structures/lists/vector/vector.c
	data_structures/lists/linked_lists/singly_linked_list/singlylinklist.c
	data_structures/lists/linked_lists/doubly_linked_list/doublylinklist.c
)

