#include "vector.h"

vector* init_vector(uint32_t init_size, void (*destroy)(vector*))
{
	assert(init_size != 0 && destroy != NULL);

	vector* new_vector = (vector*)malloc(sizeof(vector));
	
	assert(new_vector != NULL);

	new_vector->arr = (void**)calloc((init_size), sizeof(void*));

	assert(new_vector->arr != NULL);

	new_vector->capacity = init_size;
	new_vector->elements = 0;
	new_vector->destructor = destroy;
	return new_vector;
}

void resize_vector(vector* current_vector)
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

void shrink_vector(vector* current_vector)
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

void push_vector(vector* current_vector, const void* element)
{
	assert(current_vector != NULL && element != NULL && current_vector->arr != NULL);

	if (current_vector->elements == current_vector->capacity)
	{
		resize_vector(current_vector);
	}

	current_vector->arr[(current_vector->elements)++] = element;
	return;
}

void insert_vector(vector* current_vector, const void* element, uint32_t index)
{
	assert(current_vector != NULL && element != NULL && current_vector->arr != NULL);
	assert(index < current_vector->elements);

	if (current_vector->elements == current_vector->capacity)
	{
		resize_vector(current_vector);
	}

	for (uint32_t i = current_vector->elements; i > index; i--)
	{
		current_vector->arr[i] = current_vector->arr[i - 1];
	}

	current_vector->arr[index] = element;
	(current_vector->elements)++;
	return;
}

void* pop_vector(vector* current_vector)
{
	assert(current_vector != NULL && current_vector->arr != NULL);
	
	void* element = current_vector->arr[--(current_vector->elements)];
	
	current_vector->arr[(current_vector->elements) + 1] = NULL;
	return element;
}

void* remove_vector(vector* current_vector, uint32_t index)
{
	assert(current_vector != NULL && current_vector->arr != NULL);
	assert(index < (current_vector->elements) - 1);

	void* element = current_vector->arr[index];

	for (uint32_t i = index; i < (current_vector->elements) - 1; i++)
	{
		current_vector->arr[i] = current_vector->arr[i + 1];
	}

	current_vector->arr[--(current_vector->elements)] = NULL;
	return element;
}

const void* atIndex(vector* current_vector, uint32_t index)
{
	assert(current_vector != NULL && current_vector->arr != NULL);
	assert(index < current_vector->elements);
	
	return (const void*)current_vector->arr[index];
}

void swap(const void* element_a, const void* element_b)
{
	void* temp = element_a;
	element_a = element_b;
	element_b = temp;
	return;
}

void destroy_vector(vector* current_vector)
{
	assert(current_vector != NULL && current_vector->arr != NULL);
	current_vector->destructor(current_vector);
	free(current_vector);
	return;
}