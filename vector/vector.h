#ifndef VECTOR
#define VECTOR

typedef enum error_codes_vectors
{
	VECTOR_OK,
	VECTOR_INIT_FAIL,
	VECTOR_RESIZE_FAIL,
	NO_SUCH_ELEMENT_FAIL,
	INVALID_ELEMENT_ARG,


}	errorVectors;

const char* vector_error_messages[] = {
	"No error!",
	"Vector could not be initialized!",
	"Vector could not be resized",
	"No such Element exists!",
	"Invalid argument given!"
}

typedef struct vector
{
	void** arr;
	uint32_t max_capacity;
	uint32_t elements;
	
	void (*destroy_fn)(void*);                               // function for freeing the data provided by user
	const void* (*comparision_fn)(const void*, const void*); // returns a pointer to the greater element
}	vector;

vector* initVector(uint32_t init_size, void (*destroy_fn)(void*), const void* (*comparision_fn)(const void*, const void*));

static void resize(vector* vector1);

void insert(vector* vector1, const void* element, uint32_t index);

void push(vector* vector1, const void* element);

const void* remove(vector* vector1, uint32_t index);

const void* pop(vector* vector1);

const void* clear(vector* vector1);

const void* atIndex(vector* vector1, uint32_t index);

const void* contains(vector* vector1, const void* element);

uint32_t capacity(vector* vector_1, uint32_t* capacity);



#endif