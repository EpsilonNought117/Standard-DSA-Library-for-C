#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

typedef struct circular_queue
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;
	uint32_t next_remove_idx;

	void (*destructor)(void**);

}	circular_queue;

circular_queue* init_queue(uint32_t init_size, void (*destroy)(void**));

void resize(circular_queue* queue);

void shrink_to_fit(circular_queue* queue);

void enqueue(circular_queue* queue, const void* element);

void* dequeue(circular_queue* queue);

void destroy(circular_queue* queue);

#endif