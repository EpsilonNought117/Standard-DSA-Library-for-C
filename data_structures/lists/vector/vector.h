#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>

typedef struct vector
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;

	void (*destructor)(void**);
}	vector;

vector* init_vector(uint32_t init_size, void (*destroy)(void**));

void resize_vector(vector* current_vector);

void shrink_vector(vector* current_vector);

void push_vector(vector* current_vector, const void* element);

void insert_vector(vector* current_vector, const void* element, uint32_t index);

void* pop_vector(vector* current_vector);

void* remove_vector(vector* current_vector, uint32_t index);

const void* atIndex(vector* current_vector, uint32_t index);

void swap(const void* element_a, const void* element_b);

void destroy_vector(vector* current_vector);   // user defined destroy function that frees the array of void pointers

#endif