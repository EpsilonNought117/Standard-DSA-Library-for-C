#include "deque.h"

Deque* init_deque(uint32_t init_size, void (*destroy)(void**, uint32_t))
{
	assert(init_size != 0 && destroy != NULL);

	deque* new_deque = (deque*)malloc(sizeof(deque));

	assert(new_deque != NULL);

	new_deque->arr = (void**)calloc(init_size, (sizeof(void**)));

	assert(new_deque->arr != NULL);

	new_deque->capacity = init_size;
	new_deque->elements = 0;
	new_deque->front_idx = 0;
	new_deque->back_idx = 0;
	new_deque->destructor = destroy;

	return new_deque;
}

void resize_deque(Deque* deque)
{
	assert(deque != NULL);
	assert(deque->capacity < UINT32_MAX);

	uint32_t new_size = (deque->capacity > UINT32_MAX / 2 ? UINT32_MAX : 2 * (deque->capacity));

	void** temp_ptr = (void**)calloc(new_size, sizeof(void**));

	assert(temp_ptr != NULL);

	uint32_t num_elem_front = deque->capacity - deque->front_idx;	// num of elements before wrap around happens
	uint32_t num_elem_back = deque->elements - num_elem_front;		// num of elements after wrap around, if zero, indicates no elements

	memcpy(temp_ptr, deque->arr[deque->front_idx], sizeof(void**) * num_elem_front);
	memcpy(temp_ptr + num_elem_front, deque->arr, sizeof(void**) * num_elem_back);

	free(deque->arr);
	deque->arr = temp_ptr;
	deque->capacity = new_size;
	return;
}

void shrink_deque(Deque* deque)
{
	assert(deque != NULL && deque->arr != NULL);
	
	if (deque->elements == deque->capacity)
	{
		return;
	}

	void** temp_shrunk_arr_ptr = (void**)realloc(dequeue->arr, sizeof(void**) * deque->elements);

	assert(temp_shrunk_arr_ptr != NULL);

	deque->arr = temp_shrunk_arr_ptr;
	deque->capacity = deque->elements;
	return;
}

void enqueue_front(Deque* deque, const void* element)
{
	assert(deque != NULL && deque->arr != NULL && element != NULL);

	if (deque->capacity == deque->elements)
	{
		resize_deque(deque);
	}

	uint32_t new_front_idx = (deque->front_idx + deque->capacity - 1) % (deque->capacity);

	deque->arr[new_front_idx] = element;
	deque->front_idx = new_front_idx;
	(deque->elements)++;

	return;
}

void enqueue_back(Deque* deque, const void* element)
{
	assert(deque != NULL && deque->arr != NULL && element != NULL);

	if (deque->capacity == deque->elements)
	{
		resize_deque(deque);
	}

	uint32_t new_back_idx = (deque->back_idx + deque->capacity + 1) % (deque->capacity);

	deque->arr[new_back_idx] = element;
	deque->back_idx = new_back_idx;
	(deque->elements)++;

	return;
}

void* dequeue_front(Deque* deque)
{
	assert(deque != NULL && deque->arr != NULL);

	uint32_t new_front_index = (deque->front_idx + deque->capacity + 1) % (deque->capacity);

	void* element = deque->arr[new_front_index];
	deque->arr[new_front_index] = NULL;
	deque->front_idx = new_front_index;
	(deque->elements)--;

	return element;
}

void* dequeue_back(Deque* deque)
{
	assert(deque != NULL && deque->arr != NULL);

	uint32_t new_back_index = (deque->back_idx + deque->capacity + 1) % (deque->capacity);

	void* element = deque->arr[new_back_index];
	deque->arr[new_back_index] = NULL;
	deque->back_idx = new_back_index;
	(deque->elements)--;

	return element;
}

const void* peek_front_deque(Deque* deque)
{
	assert(deque != NULL && deque->arr != NULL);

	return (const void*)(deque->arr[deque->front_idx]);
}

const void* peek_back_deque(Deque* deque)
{
	assert(deque != NULL && deque->arr != NULL);

	return (const void*)(deque->arr[deque->back_idx]);
}

void destroy_deque(Deque* current_deque)
{
	assert(current_deque != NULL && current_deque->arr != NULL);
	current_deque->destructor(current_deque->arr, current_deque->elements);
	current_deque->arr = NULL;
	free(current_deque);
	return;
}