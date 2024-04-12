#include "vector.h"
#include "sorting.h"
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// BUBBLE SORT

void bubbleSort(vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	for (uint32_t i = 0; i < vector->elements; i++)
	{
		bool flag = true;

		for (uint32_t j = 1; j < vector->elements - i; j++)
		{
			if (comparator(vector->arr[j], vector->arr[j - 1]) == lesser)
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

void selectionSort(vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	for (uint32_t i = 0; i < vector->elements; i++)
	{
		uint32_t min_index = 0;

		for (uint32_t j = i + 1; j < vector->elements; j++)
		{
			if (comparator(vector->arr[j], vector->arr[j - 1]) == lesser)
			{
				min_index = j;
			}

			swap(vector->arr[min_index], vector->arr[i]);
		}
	}

	return;
}

// INSERTION SORT

void insertionSort(vector* vector, result(*comparator)(const void*, const void*))
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

void binaryInsertionSort(vector* vector, result(*comparator)(const  void*, const void*))
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

static uint32_t binarySearchIndex(vector* vector, const void* key, result(*comparator)(const void*, const void*), uint32_t check_till_index)
{
	uint32_t insert_index = 0;

	while (insert_index <= check_till_index)
	{
		uint32_t current_index = insert_index + ((check_till_index - insert_index) / 2);
		result compare_result = comparator(vector->arr[current_index], key);

		if (compare_result == lesser)
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

void mergeSort(vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL && vector->arr != NULL && comparator != NULL);

	mergeSortRecursive(vector->arr, 0, vector->elements - 1, comparator);
	return;
}

// MERGE SORT RECURSIVE HELPER FUNCTION

static void mergeSortRecursive(void** arr, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*))
{
	if (front_idx == back_idx)
	{
		return;
	}

	uint32_t mid_idx = front_idx + ((back_idx - front_idx) >> 1);

	mergeSortRecursive(arr, front_idx, mid_idx, comparator);
	mergeSortRecursive(arr, mid_idx + 1, back_idx, comparator);
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
		if (comparator(*(arr_left + i), *(arr_right + j)) == lesser)
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