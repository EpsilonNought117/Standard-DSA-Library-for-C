#include "singlylinklist.h"

singlylinklist* init_sll(void (*destroy)(sllnode*))
{
	assert(destroy != NULL);

	singlylinklist* new_list = (singlylinklist*)malloc(sizeof(singlylinklist));

	assert(new_list != NULL);

	new_list->head_sll = NULL, new_list->tail_sll = NULL;
	new_list->length = 0;

	new_list->destructor = destroy;
	return new_list;
}

sllnode* init_sllnode(const void* data)
{
	assert(data != NULL);

	sllnode* new_node = (sllnode*)malloc(sizeof(sllnode));

	assert(new_node != NULL);

	new_node->node_data = data;
	new_node->next_ptr = NULL;
	return new_node;
} 

void insert_node_sll(singlylinklist* list, sllnode* node, sllnode* position)
{
	assert(list->length < UINT32_MAX);
	assert(list != NULL && node != NULL);
	
	if (position == list->head_sll)
	{
		node->next_ptr = list->head_sll;
		list->head_sll = node;

		list->tail_sll = (list->tail_sll == NULL ? node : list->tail_sll);
	}
	else if (position == list->tail_sll)
	{
		list->tail_sll->next_ptr = node;
		list->tail_sll = node;
	}
	else
	{
		node->next_ptr = position->next_ptr;
		position->next_ptr = node;
	}

	(list->length)++;
	return;
}

sllnode* remove_node_sll(singlylinklist* list, sllnode* position)
{
	assert(list->length > 0);
	assert(list != NULL && position != NULL);

	sllnode* temp = (position == list->head_sll ? position : position->next_ptr);

	if (temp == list->head_sll)
	{
		list->tail_sll = (list->tail_sll == list->head_sll ? NULL : list->tail_sll);
		list->head_sll = list->head_sll->next_ptr;
	}
	else if (temp == list->tail_sll)
	{
		position->next_ptr = NULL;
		list->tail_sll = position;
	}
	else
	{
		assert(position != list->tail_sll);

		position->next_ptr = temp->next_ptr;
		temp->next_ptr = NULL;
	}

	(list->length)--;
	return temp;
}

const sllnode* peek_node_sll(singlylinklist* list, sllnode* position)
{
	assert(list != NULL && list->head_sll != NULL && position != NULL);

	return position;
}

void destroy_sll(singlylinklist* list)
{
	assert(list != NULL && list->head_sll != NULL);
	
	sllnode* current_node = list->head_sll;

	list->head_sll == NULL;
	list->tail_sll == NULL;

	while (current_node)
	{
		sllnode* next_node = current_node->next_ptr;
		current_node->next_ptr = NULL;
		list->destructor(current_node);
		current_node = next_node;
	}

	free(list);
	list = NULL;
	return;
}
