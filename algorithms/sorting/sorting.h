#ifndef SORTING
#define SORTING

typedef enum comparision_result
{
	// for comparator(const void* a, const void* b)

	lesser = -1,	// a < b
	equal,			// a == b
	greater			// a > b

}	result;

// comparision function: int32_t (*comparator)(const void*, const void*);

void bubbleSort(vector* vector, result (*comparator)(const void*, const void*));

void selectionSort(vector* vector, result (*comparator)(const void*, const void*));

void insertionSort(vector* vector, result(*comparator)(const void*, const void*));

void binaryInsertionSort(vector* vector, result(*comparator)(const void*, const void*));

static uint32_t binarySearchIndex(vector* vector, const void* key, result(*comparator)(const void*, const void*), uint32_t check_till_index);

void mergeSort(vector* vector, result(*comparator(const void*, const void*));

static void mergeSortHelper(void** arr, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*));

static void merge(void** arr, uint32_t front_idx, uint32_t mid_idx, uint32_t back_idx, result(*comparator)(const  void*, const void*));

void heapSort(vector* vector, result(*comparator)(const void*, const void*));

static void buildMaxHeap(vector* vector, uint32_t heap_size, result(*comparator)(const void*, const void*));

static void maxHeapify(vector* vector, uint32_t index, uint32_t heap_size, result(*comparator)(const void*, const void*));

void quickSort(vector* vector, result(*comparator)(const void*, const void*));

static void quickSortHelper(vector* vector, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*));

static uint32_t randomized_partition(vector* vector, uint32_t front_idx, uint32_t back_idx, result(*comparator)(const void*, const void*));

void shellSort(vector* vector, result(*comparator)(const void*, const void*));

#endif