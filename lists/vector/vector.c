#include "vector.h"
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>

vector* init_vector(uint32_t init_size, void (*destroy)(void**))
{
	assert(init_size != 0 || destroy != NULL);

	vector* new_vector = (vector*)malloc(sizeof(vector));
	
	assert(new_vector != NULL);

	new_vector->arr = (void**)calloc((init_size), sizeof(void*));

	assert(new_vector->arr != NULL);

	new_vector->capacity = init_size;
	new_vector->elements = 0;
	new_vector->destructor = destroy;
	return new_vector;
}

void resize(vector* current_vector)
{
	assert(current_vector != NULL);
	assert(current_vector->capacity < UINT32_MAX);

	uint32_t new_capacity = (current_vector->capacity > UINT32_MAX / 2 ? UINT32_MAX : (current_vector->capacity) * 2);

	void** temp_ptr_resized_arr = (void**)realloc(current_vector->arr, sizeof(void**) * new_capacity);

	assert(temp_ptr_resized_arr != NULL);

	current_vector->arr = temp_ptr_resized_arr;
	current_vector->capacity = new_capacity;
	return;
}

void shrink_to_fit(vector* current_vector)
{
	assert(current_vector != NULL);

	if (current_vector->capacity == current_vector->elements)
	{
		return;
	}

	void** temp_ptr_shrunk_arr = (void**)realloc(current_vector->arr, sizeof(void**) * current_vector->elements);

	assert(temp_ptr_shrunk_arr != NULL);

	current_vector->arr = temp_ptr_shrunk_arr;
	current_vector->capacity = current_vector->elements;
	return;
}

void push(vector* current_vector, const void* element)
{
	assert(current_vector != NULL || element != NULL || current_vector->arr != NULL);

	if (current_vector->elements == current_vector->capacity)
	{
		resize(current_vector);
	}

	current_vector->arr[(current_vector->elements)++] = element;
	return;
}

void insert(vector* current_vector, const void* element, uint32_t index)
{
	assert(current_vector != NULL || element != NULL || current_vector->arr != NULL);
	assert(index < current_vector->elements);

	if (current_vector->elements == current_vector->capacity)
	{
		resize(current_vector);
	}

	for (uint32_t i = current_vector->elements; i > index; i--)
	{
		current_vector->arr[i] = current_vector->arr[i - 1];
	}

	current_vector->arr[index] = element;
	(current_vector->elements)++;
	return;
}

void* pop(vector* current_vector)
{
	assert(current_vector != NULL || current_vector->arr != NULL);
	
	void* element = current_vector->arr[--(current_vector->elements)];
	
	current_vector->arr[(current_vector->elements) + 1] = NULL;
	return element;
}

void* remove(vector* current_vector, uint32_t index)
{
	assert(current_vector != NULL || current_vector->arr != NULL);
	assert(index < (current_vector->elements) - 1);

	void* element = current_vector->arr[index];

	for (uint32_t i = index; i < (current_vector->elements) - 1; i++)
	{
		current_vector->arr[i] = current_vector->arr[i + 1];
	}

	current_vector->arr[--(current_vector->elements)] = NULL;
	return element;
}

void* atIndex(vector* current_vector, uint32_t index)
{
	assert(current_vector != NULL || current_vector->arr != NULL);
	assert(index < current_vector->elements);
	
	return (void*)current_vector->arr[index];
}

void destroy(vector* current_vector)
{
	assert(current_vector != NULL || current_vector->arr != NULL);
	current_vector->destructor(current_vector->arr);
	free(current_vector);
	return;
}