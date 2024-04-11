#ifndef VECTOR
#define VECTOR

typedef struct vector
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;

	void (*destructor)(void**);
}	vector;

vector* init_vector(uint32_t init_size, void (*destroy)(void**));

void resize(vector* current_vector);

void shrink_to_fit(vector* current_vector);

void push(vector* current_vector, const void* element);

void insert(vector* current_vector, const void* element, uint32_t index);

void* pop(vector* current_vector);

void* remove(vector* current_vector, uint32_t index);

void* atIndex(vector* current_vector, uint32_t index);

void swap(const void* element_a, const void* element_b);

void destroy(vector* current_vector);   // user defined destroy function that frees the array of void pointers

#endif