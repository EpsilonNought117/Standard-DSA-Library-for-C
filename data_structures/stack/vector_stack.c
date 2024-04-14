#include "vector.h"
#include "vector_stack.h"

stack* init_stack(uint32_t init_size, void (*destroy)(void**))
{
	return (stack*)init_vector(init_size, destroy);
}

void resize_stack(stack* stack)
{
	return resize_vector(stack);
}

void shrink_stack(stack* stack)
{
	return shrink_vector(stack);
}

void stack_push(stack* stack, const void * element)
{
	return push_vector(stack, element);
}

void* stack_pop(stack* stack)
{
	return pop_vector(stack);
}

const void* peek_stack(stack* stack)
{
	return atIndex(stack, stack->elements - 1);
}

void destroy_stack(stack* stack)
{
	return destroy_vector(stack);
}