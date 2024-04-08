#ifndef VECTOR
#define VECTOR

typedef enum error_codes_vectors
{
	VECTOR_INIT_FAIL,
	VECTOR_RESIZE_FAIL,
	VECTOR_NO_SUCH_ELEMENT_FAIL,

}	errorVectors;

typedef struct dynamic_arr
{
	void** arr;
	uint64_t max_capacity;
	uint64_t elements;
	
	void (*destroy_fn)(void*);                               // function for freeing the data provided by user
	const void* (*comparision_fn)(const void*, const void*); // returns a pointer to the greater element
}	vector;

errorVectors initVector(vector* vector1, uint64_t init_size, void (*destroy_fn)(void*), const void* (*comparision_fn)(const void*, const void*));

static errorVectors resize(vector* vector1);

errorVectors insert(vector* vector1, const void* element, uint64_t index);

errorVectors push(vector* vector1, const void* element);

errorVectors remove(vector* vector1, const void* element, uint64_t index);

errorVectors pop(vector* vector1, const void* element);

errorVectors 

#endif