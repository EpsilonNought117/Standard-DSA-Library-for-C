#include "deque.h"
#include "queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

queue* init_queue(uint32_t init_size, void (*destroy)(void**))
{
	return (queue*)init_queue(init_queue, destroy);
}

void resize_queue(queue* queue)
{
	return resize_deque(queue);
}

void shrink_queue(queue* queue)
{
	return shrink_deque(queue);
}

void enqueue(queue* queue, const void* element)
{
	return enqueue_back(queue, element);
}

void dequeue(queue* queue)
{
	return dequeue_front(queue, element);
}

const void* least_recent(queue* queue)
{
	return peek_front_deque(queue);
}

const void* most_recent(queue* queue)
{
	return peek_back_deque(queue);
}

void destroy_queue(queue* queue)
{
	return destroy_deque(queue);
}