#include "circular_queue.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

circular_queue* init_queue(uint32_t init_size, void (*destroy)(void**))
{
	assert(init_size != 0 || destroy != NULL);

	circular_queue* new_queue = (circular_queue*)malloc(sizeof(circular_queue));

	assert(new_queue != NULL);

	new_queue->arr = (void**)calloc(init_size, (sizeof(void**)));

	assert(new_queue->arr != NULL);

	new_queue->capacity = init_size;
	new_queue->elements = 0;
	new_queue->next_remove_idx = 0;
	new_queue->destructor = destroy;

	return new_queue;
}

void resize_queue(circular_queue* queue)
{
	assert(queue != NULL);
	assert(queue->capacity < UINT32_MAX);

	uint32_t new_size = (queue->capacity > UINT32_MAX / 2 ? UINT32_MAX : 2 * (queue->capacity));

	void** temp_ptr = (void**)calloc((new_size, (sizeof(void**)));

	assert(temp_ptr != NULL);

	uint32_t num_elem_cpy_old = queue->capacity - queue->next_remove_idx;    // num of elements before wrap around happens
	uint32_t num_elem_cpy_new = queue->elements - num_elem_cpy_old;              // num of elements after wrap around, if zero, indicates no elements

	memcpy(temp_ptr, queue->arr[queue->next_remove_idx], sizeof(void**) * num_elem_cpy_old);
	memcpy(temp_ptr + num_elem_cpy_old, queue->arr, sizeof(void**) * num_elem_cpy_new);
	
	free(queue->arr);
	queue->arr = temp_ptr;
	queue->capacity = new_size;
	return;
}

void shrink_queue(circular_queue* queue)
{
	assert(queue != NULL);

	if (queue->elements == queue->capacity)
	{
		return;
	}

	void** temp_shrunk_arr = (void**)realloc(queue->arr, sizeof(void**) * queue->elements);

	assert(temp_shrunk_arr != NULL);

	queue->arr = temp_shrunk_arr;
	queue->capacity = queue->elements;
	return;
}

void enqueue(circular_queue* queue, const void* element)
{
	assert(queue != NULL || queue->arr != NULL || element != NULL);

	if (queue->elements == queue->capacity)
	{
		resize_queue(queue);
	}

	queue->arr[(queue->next_remove_idx + queue->elements) % (queue->capacity)] = element;
	(queue->elements)++;
	return;
}

void* dequeue(circular_queue* queue)
{
	assert(queue != NULL || queue->arr != NULL);

	void* element = queue->arr[queue->next_remove_idx];
	queue->arr[queue->next_remove_idx] = NULL;
	(queue->elements)--;
	return element;
}

void* peek_front(circular_queue* queue)
{
	assert(queue != NULL || queue->arr != NULL);

	return (void*)queue->arr[queue->next_remove_idx];
}

void* peek_end(circular_queue* queue)
{
	assert(queue != NULL || queue->arr != NULL);

	return (void*)queue->arr[(queue->next_remove_idx + queue->elements) % queue->capacity];
}

void destroy(circular_queue* queue)
{
	assert(queue != NULL || queue->destructor != NULL);
	queue->destructor(queue->arr);
	free(queue);
	return;
}