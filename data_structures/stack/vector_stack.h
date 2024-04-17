#ifndef VECTOR_STACK
#define VECTOR_STACK

#include <stdint.h>
#include "../lists/vector/vector.h"

typedef Vector Stack;

Stack* init_stack(uint32_t init_size, void (*destroy)(void**, uint32_t));

void resize_stack(Stack* stack);

void shrink_stack(Stack* stack);

void stack_push(Stack* stack, const void* element);

void* stack_pop(Stack* stack);

const void* peek_stack(Stack* stack);

void destroy_stack(Stack* stack);

#endif
