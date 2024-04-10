#ifndef VECTOR
#define VECTOR

typedef struct vector
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;
}	vector;

vector* init(uint32_t init_size);

void resize(vector* current_vector);

void shrink_to_fit(vector* current_vector);

void push(vector* current_vector, const void* element);

void insert(vector* current_vector, const void* element, uint32_t index);

void* pop(vector* current_vector);

void* remove(vector* current_vector, uint32_t index);

void destroy(vector* current_vector, void (*destroy)(void*));

void* hasElement(vector* current_vector);   // return NULL if element not found
#endif