#include "vector.h"
#include "sorting.h"
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// BUBBLE SORT

void bubbleSort(vector* vector, result(*comparator)(const void*, const void*))
{
	assert(vector != NULL || vector->arr != NULL || comparator != NULL);

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
	assert(vector != NULL || vector->arr != NULL || comparator != NULL);

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
	assert(vector != NULL || vector->arr != NULL || comparator != NULL);

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
	assert(vector != NULL || vector->arr != NULL || comparator != NULL);

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

uint32_t binarySearchIndex(vector* vector, const void* key, result(*comparator)(const void*, const void*), uint32_t check_till_index)
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

//