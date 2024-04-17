#include "vector_stack.h"

Stack* init_stack(uint32_t init_size, void (*destroy)(void**, uint32_t))
{
	return (Stack*)init_vector(init_size, destroy);
}

void resize_stack(Stack* stack)
{
	return resize_vector(stack);
}

void shrink_stack(Stack* stack)
{
	return shrink_vector(stack);
}

void stack_push(Stack* stack, const void * element)
{
	return push_vector(stack, element);
}

void* stack_pop(Stack* stack)
{
	return pop_vector(stack);
}

const void* peek_stack(Stack* stack)
{
	return atIndex(stack, stack->elements - 1);
}

void destroy_stack(Stack* stack)
{
	return destroy_vector(stack);
}