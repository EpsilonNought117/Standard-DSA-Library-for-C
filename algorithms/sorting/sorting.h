#ifndef SORTING
#define SORTING

#include "../data_structures/lists/vector/vector.h"

typedef enum comparision_result
{
	// for comparator(const void* a, const void* b)

	lesser_or_equal,	// a <= b
	greater				// a > b

}	result;

// comparision function: int32_t (*comparator)(const void*, const void*);

void bubbleSort(Vector* vector, result (*comparator)(const void*, const void*));

void selectionSort(Vector* vector, result (*comparator)(const void*, const void*));

void insertionSort(Vector* vector, result(*comparator)(const void*, const void*));

void binaryInsertionSort(Vector* vector, result(*comparator)(const void*, const void*));

void mergeSort(Vector* vector, result(*comparator)(const void*, const void*));

void heapSort(Vector* vector, result(*comparator)(const void*, const void*));

void quickSort(Vector* vector, result(*comparator)(const void*, const void*));

#endif