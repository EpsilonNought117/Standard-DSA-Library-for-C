#include "vector.h"
#include "vector_stack.h"
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>

stack* init_stack(uint32_t init_size, void (*destroy)(void**))
{
	return init_vector(init_size, destroy);
}

void resize_stack(stack* stack)
{
	return resize(stack);
}

void shrink_stack(stack* stack)
{
	return shrink_to_fit(stack);
}

void stack_push(stack* stack, const void * element)
{
	return push(stack, element);
}

void* stack_pop(stack* stack)
{
	return pop(stack);
}

const void* peek_stack(stack* stack)
{
	return atIndex(stack, stack->elements - 1);
}

void destroy_stack(stack* stack)
{
	return destroy(stack);
}