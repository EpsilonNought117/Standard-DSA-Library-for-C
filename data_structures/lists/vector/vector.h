#ifndef VECTOR
#define VECTOR

#include <stdint.h>

typedef struct Vector
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;

	void (*destructor)(void** arr, uint32_t);
}	Vector;

Vector* init_vector(uint32_t init_size, void (*destroy)(void**, uint32_t));

void resize_vector(Vector* current_vector);

void shrink_vector(Vector* current_vector);

void push_vector(Vector* current_vector, const void* element);

void insert_vector(Vector* current_vector, const void* element, uint32_t index);

void* pop_vector(Vector* current_vector);

void* remove_vector(Vector* current_vector, uint32_t index);

const void* atIndex(Vector* current_vector, uint32_t index);

void swap(void** element_a, void** element_b);

void destroy_vector(Vector* current_vector);   // user defined destroy function that frees the array of void pointers

#endif