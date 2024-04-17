#ifndef VECTOR_STACK
#define VECTOR_STACK

#include "../header_to_include/std_dsa_lib.h"
#include "..lists/vector/vector.h"

typedef vector stack;

stack* init_stack(uint32_t init_size, void (*destroy)(void**, uint32_t));

void resize_stack(stack* stack);

void shrink_stack(stack* stack);

void stack_push(stack* stack, const void* element);

void* stack_pop(stack* stack);

const void* peek_stack(stack* stack);

void destroy_stack(stack* stack);

#endif
