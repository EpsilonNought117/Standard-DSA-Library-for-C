#include <stdio.h>

typedef struct example
{
	uint32_t val;
}	example;

result comparision_fn(const void*, const void*);
void destroy_fn(void**, uint32_t);

int main(void)
{
	uint32_t size = 256;
	vector* v1 = init_vector(size, &destroy_fn);

	for (uint32_t i = 0; i < size; i++)
	{
		example* my_struct = (example*)malloc(sizeof(example));
		my_struct->val = rand() % size;
		printf("%ui ", my_struct->val);

		push_vector(v1, my_struct);
	}
	
	printf("\n");

	insertionSort(v1, &comparision_fn);

	for (uint32_t j = 0; j < size; j++)
	{
		example* curr_struct = (example*)atIndex(v1, j);
		printf("%ui ", curr_struct->val);
	}

	destroy_vector(v1);

	if (v1 != NULL)
	{
		printf("\nVector not destroyed!");
	}
	else
	{
		printf("\nVector destroyed!");
	}

	return 0;
}

void destroy_fn(void** arr, uint32_t size)
{
	for (uint32_t i = 0; i < size; i++)
	{
		example* x = (example*)arr[i];
		free(x);
		arr[i] = NULL;
	}
	
	free(arr);
	arr = NULL;
	return;
}

result comparision_fn(const void* a, const void* b)
{
	example* x = (example*)a;
	example* y = (example*)b;

	return (x->val > y->val ? greater : lesser_or_equal);
}