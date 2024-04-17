#include "../header_to_include/std_dsa_lib.h"

Queue* init_queue(uint32_t init_size, void (*destroy)(void**, uint32_t))
{
	return (Queue*)init_deque(init_size, destroy);
}

void resize_queue(Queue* queue)
{
	return resize_deque(queue);
}

void shrink_queue(Queue* queue)
{
	return shrink_deque(queue);
}

void enqueue(Queue* queue, const void* element)
{
	return enqueue_back(queue, element);
}

void dequeue(Queue* queue)
{
	return dequeue_front(queue, element);
}

const void* least_recent(Queue* queue)
{
	return peek_front_deque(queue);
}

const void* most_recent(Queue* queue)
{
	return peek_back_deque(queue);
}

void destroy_queue(Queue* queue)
{
	return destroy_deque(queue);
}