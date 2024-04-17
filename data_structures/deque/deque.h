#ifndef DEQUE
#define DEQUE

#include <stdint.h>

typedef struct Deque
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;
	uint32_t front_idx;
	uint32_t back_idx;
	
	void (*destructor)(void**, uint32_t);
}	Deque;

Deque* init_deque(uint32_t init_size, void (*destroy)(void**, uint32_t));

void resize_deque(Deque* deque);

void shrink_deque(Deque* deque);

void enqueue_front(Deque* deque, const void* element);

void enqueue_back(Deque* deque, const void* element);

void* dequeue_front(Deque* deque);

void* dequeue_back(Deque* deque);

const void* peek_front_deque(Deque* deque);

const void* peek_back_deque(Deque* deque);

void destroy_deque(Deque* deque);

#endif