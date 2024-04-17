#ifndef QUEUE
#define QUEUE

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

typedef deque queue;

queue* init_queue(uint32_t init_size, void (*destroy)(void**, uint32_t));

void resize_queue(queue* queue);

void shrink_queue(queue* queue);

void enqueue(queue* queue, const void* element);

void* dequeue(queue* queue);

const void* least_recent(queue* queue);

const void* most_recent(queue* queue);

void destroy_queue(queue* queue);

#endif