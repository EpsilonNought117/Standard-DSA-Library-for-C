#ifndef VECTOR_STACK
#define VECTOR_STACK

typedef vector stack;

stack* init_stack(uint32_t init_size, void (*destroy)(void**));

void resize_stack(stack* stack);

void shrink_stack(stack* stack);

void stack_push(stack* stack, const void* element);

void* stack_pop(stack* stack);

const void* peek_stack(stack* stack);

void destroy_stack(stack* stack);

#endif
