#ifndef DEQUE
#define DEQUE

typedef struct deque
{
	void** arr;
	uint32_t capacity;
	uint32_t elements;
	uint32_t front_idx;
	uint32_t back_idx;

	void (*destructor)(void**);
}	deque;

deque* init_deque(uint32_t init_size, void (*destroy)(void**));

void resize_deque(deque* deque);

void shrink_deque(deque* deque);

void enqueue_front(deque* deque, const void* element);

void enqueue_back(deque* deque, const void* element);

void* dequeue_front(deque* deque);

void* dequeue_back(deque* deque);

const void* peek_front_deque(deque* deque);

const void* peek_back_deque(deque* deque);

void destroy(deque* deque);

#endif