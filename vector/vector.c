#include "vector.h"
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

vector* init(uint32_t init_size, void (*destructor)(void*))
{
	assert(init_size == 0 || init_size <= UINT32_MAX / 8);

	vector* new_vector = (vector*)malloc(sizeof(vector));
	
	assert(new_vector != NULL);

	new_vector->arr = (void**)calloc((size_t)(init_size), (size_t)sizeof(void*));

	assert(new_vector->arr != NULL);

	new_vector->capacity = init_size;
	new_vector->elements = 0;
	return new_vector;
}

void resize(vector* current_vector)
{
	if (current_vector->capacity == UINT32_MAX)
	{
		assert(current_vector->capacity <= UINT32_MAX);
	}

	uint32_t new_capacity = (current_vector->capacity > UINT32_MAX / 2 ? UINT32_MAX : (current_vector->capacity) * 2);

	void** temp_ptr_resized_arr = (void**)realloc((void*)current_vector->arr, (size_t)(sizeof(void**) * new_capacity);

	assert(temp_ptr_resized_arr != NULL);

	current_vector->arr = temp_ptr_resized_arr;
	temp_ptr_resized_arr = NULL;
	current_vector->capacity = new_capacity;

	return;
}

void shrink_to_fit(vector* current_vector)
{
	
}