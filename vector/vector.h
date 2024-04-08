#ifndef VECTOR
#define VECTOR

typedef enum error_codes_vectors
{
	VECTOR_INIT_FAIL,
	VECTOR_RESIZE_FAIL,
	NO_SUCH_ELEMENT_FAIL,
	INVALID_ELEMENT_ARG
}	errorVectors;

typedef struct dynamic_arr
{
	void** arr;
	uint32_t max_capacity;
	uint32_t elements;
	
	void (*destroy_fn)(void*);                               // function for freeing the data provided by user
	const void* (*comparision_fn)(const void*, const void*); // returns a pointer to the greater element
}	vector;

errorVectors initVector(vector* vector1, uint32_t init_size, void (*destroy_fn)(void*), const void* (*comparision_fn)(const void*, const void*));

static errorVectors resize(vector* vector1);

errorVectors insert(vector* vector1, const void* element, uint32_t index);

errorVectors push(vector* vector1, const void* element);

errorVectors remove(vector* vector1, const void* element, uint32_t index);

errorVectors pop(vector* vector1, const void* element);

errorVectors clear(vector* vector1);

errorVectors atIndex(vector* vector1, uint32_t index);

errorVectors contains(vector* vector1, const void* element);

#endif