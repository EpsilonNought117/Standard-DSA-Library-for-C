#ifndef QUEUE
#define QUEUE

#include "../header_to_include/std_dsa_lib.h"

typedef Deque Queue;

Queue* init_queue(uint32_t init_size, void (*destroy)(void**, uint32_t));

void resize_queue(Queue* queue);

void shrink_queue(Queue* queue);

void enqueue(Queue* queue, const void* element);

void* dequeue(Queue* queue);

const void* least_recent(Queue* queue);

const void* most_recent(Queue* queue);

void destroy_queue(Queue* queue);

#endif