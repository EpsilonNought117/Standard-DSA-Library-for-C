#include "sorting.h"

// HELPER FUNCTIONS FUNCTION PROTOTYPE

static void buildMaxHeap(Vector* vector, uint32_t heap_size, result(*comparator)(const void*, const void*));

static void maxHeapify(Vector* vector, uint32_t index, uint32_t heap_size, result(*comparator)(const void*, const void*));

static void quickSortHelper(Vector* vector, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*));

static uint32_t randomized_partition(Vector* vector, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*));

static void mergeSortHelper(void** arr, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*));

static void merge(void** arr, uint32_t front_idx, uint32_t mid_idx, uint32_t back_idx, result(*comparator)(const  void*, const void*));

static uint32_t binarySearchIndex(Vector* vector, const void* key, result(*comparator)(const void*, const void*), uint32_t check_till_index);

// BUBBLE SORT

void bubbleSort(Vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	for (uint32_t i = 0; i < vector->elements; i++)
	{
		bool flag = true;

		for (uint32_t j = 1; j < vector->elements - i; j++)
		{
			if (comparator(vector->arr[j], vector->arr[j - 1]) == lesser_or_equal)
			{
				swap(vector->arr[j], vector->arr[j - 1]);
				flag = false;
			}
		}

		if (flag)
		{
			break;
		}
	}

	return;
}

// SELECTION SORT

void selectionSort(Vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	for (uint32_t i = 0; i < vector->elements; i++)
	{
		uint32_t min_index = 0;

		for (uint32_t j = i + 1; j < vector->elements; j++)
		{
			if (comparator(vector->arr[j], vector->arr[j - 1]) == lesser_or_equal)
			{
				min_index = j;
			}

			swap(vector->arr[min_index], vector->arr[i]);
		}
	}

	return;
}

// INSERTION SORT

void insertionSort(Vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	for (uint32_t i = 1; i < vector->elements; i++)
	{
		const void* key = vector->arr[i];
		uint32_t j = i - 1;

		while (j >= 0 && (comparator(vector->arr[j], key) == greater))
		{
			vector->arr[j] = vector->arr[j - 1];
			j--;
		}

		vector->arr[j + 1] = key;
	}

	return
}

// BINARY INSERTION SORT

void binaryInsertionSort(Vector* vector, result(*comparator)(const  void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	for (uint32_t i = 1; i < vector->elements; i++)
	{
		const void* key = vector->arr[i];
		uint32_t j = i - 1;
		uint32_t insertion_index = binarySearchIndex(vector, key, comparator, j);

		while (j >= insertion_index)
		{
			vector->arr[j + 1] = vector->arr[j];
			j--;
		}

		vector->arr[j + 1] = key;
	}

	return;
}

// BINARY INSERTION SORT HELPER FUNCTION

static uint32_t binarySearchIndex(Vector* vector, const void* key, result(*comparator)(const void*, const void*), uint32_t check_till_index)
{
	uint32_t insert_index = 0;

	while (insert_index <= check_till_index)
	{
		uint32_t current_index = insert_index + ((check_till_index - insert_index) / 2);
		result compare_result = comparator(vector->arr[current_index], key);

		if (compare_result == lesser_or_equal)
		{
			insert_index = current_index + 1;
		}
		else
		{
			check_till_index = current_index - 1;
		}
	}

	return insert_index + 1;
}

// MERGE SORT WRAPPER FUNCTION

void mergeSort(Vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	mergeSortHelper(vector->arr, 0, vector->elements - 1, comparator);
	return;
}

// MERGE SORT HELPER FUNCTION

static void mergeSortHelper(void** arr, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*))
{
	if (front_idx == back_idx)
	{
		return;
	}

	uint32_t mid_idx = front_idx + ((back_idx - front_idx) >> 1);

	mergeSortHelper(arr, front_idx, mid_idx, comparator);
	mergeSortHelper(arr, mid_idx + 1, back_idx, comparator);
	merge(arr, front_idx, mid_idx, back_idx, comparator);
	return;
}

// MERGE HELPER FUNCTION

static void merge(void** arr, uint32_t front_idx, uint32_t mid_idx, uint32_t end_idx, result(*comparator)(const void*, const void*))
{
	uint32_t left_size = mid_idx - front_idx + 1;
	uint32_t right_size = end_idx - mid_idx;
	
	void** arr_left = (void**)malloc(left_size * sizeof(void*));
	void** arr_right = (void**)malloc(right_size * sizeof(void*));

	for (uint32_t i = 0; i < left_size; i++)
	{
		arr_left[i] = arr[front_idx + i];
	}

	for (uint32_t j = 0; j < right_size; j++)
	{
		arr_right[j] = arr[mid_idx + j + 1];
	}

	uint32_t i = 0, j = 0, k = front_idx;

	while (i < left_size && j < right_size)
	{
		if (comparator(*(arr_left + i), *(arr_right + j)) == lesser_or_equal)
		{
			arr[k] = arr_left[i];
			i++;
		}
		else
		{
			arr[k] = arr_right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		arr[k] = arr_left[i];
		i++;
		k++;
	}
	while (j < right_size)
	{
		arr[k] = arr_right[j];
		j++;
		k++;
	}

	free(arr_left);
	free(arr_right);
	return;
}

// HEAP SORT

void heapSort(Vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	uint32_t temp_heap_size = vector->elements;
	buildMaxHeap(vector, temp_heap_size, comparator);
	
	for (uint32_t i = temp_heap_size - 1; i > 0; i--)
	{
		swap(vector->arr[0], vector->arr[i]);
		temp_heap_size--;

		buildMaxHeap(vector, temp_heap_size, comparator);
	}
}

// HEAP SORT HELPER FUNCTION BUILD MAX HEAP

static void buildMaxHeap(Vector* vector, uint32_t heap_size, result(*comparator)(const void*, const void*))
{
	for (uint32_t i = vector->elements / 2; i >= 0; i--)
	{
		maxHeapify(vector, i, heap_size, comparator);
	}

	return;
}

// HEAP SORT HELPER FUNCTION MAX HEAPIFY

static void maxHeapify(Vector* vector, uint32_t index, uint32_t heap_size, result(*comparator)(const void*, const void*))
{
	while (1)
	{
		uint32_t largest_idx = index;
		uint32_t left_idx = (largest_idx << 1) + 1;
		uint32_t right_idx = (largest_idx << 1) + 2;

		if (left_idx < heap_size && comparator(vector->arr[left_idx], vector->arr[largest_idx]) == greater)
		{
			largest_idx = left_idx;
		}
		if (right_idx < heap_size && comparator(vector->arr[right_idx], vector->arr[largest_idx]) == greater)
		{
			largest_idx = right_idx;
		}

		if (largest_idx != index)
		{
			swap(vector->arr[index], vector->arr[largest_idx]);

			index = largest_idx;
		}

		else
		{
			break;
		}
	}

	return;
}

// QUICK SORT

void quickSort(Vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	quickSortHelper(vector, 0, vector->elements - 1, comparator);
	return;
}

// QUICK SORT HELPER FUNCTION

static void quickSortHelper(Vector* vector, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*))
{
	if (front_idx < back_idx)
	{
		uint32_t pivot_idx = randomized_partition(vector, front_idx, back_idx, comparator);

		quickSortHelper(vector, front_idx, pivot_idx - 1, comparator);
		quickSortHelper(vector, pivot_idx + 1, back_idx, comparator);
	}

	return;
}

// QUICK SORT HELPER FUNCTION RANDOMIZED PARTITION

static uint32_t randomized_partition(Vector* vector, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*))
{
	uint32_t random_idx = (rand() % (back_idx - front_idx + 1)) + front_idx;
	swap(vector->arr[random_idx], vector->arr[back_idx]);

	const void* pivot_element = vector->arr[back_idx];

	uint32_t i = front_idx - 1;

	for (uint32_t j = front_idx; j < back_idx; j++)
	{
		if (comparator(vector->arr[j], pivot_element) != greater)
		{
			i++;
			swap(vector->arr[i], vector->arr[j]);
		}
	}

	swap(vector->arr[i], vector->arr[back_idx]);
	return (i + 1);
}