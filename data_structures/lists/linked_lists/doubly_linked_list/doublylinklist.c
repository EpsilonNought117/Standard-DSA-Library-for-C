#include "doublylinklist.h"
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

doublylinklist* init_dll(void (*destroy)(dllnode*))
{
	assert(destroy != NULL);

	doublylinklist* list = (doublylinklist*)malloc(sizeof(doublylinklist));

	assert(list != NULL);

	list->head_dll = NULL, list->tail_dll = NULL;
	list->length = 0;
	list->destructor = destroy;

	return list;
}

dllnode* init_dllnode(const void* data)
{
	assert(data != NULL);

	dllnode* new_node = (dllnode*)malloc(sizeof(dllnode));

	assert(new_node != NULL);

	new_node->data = data;
	new_node->left_ptr = NULL, new_node->right_ptr = NULL;
	return new_node;
}

void insert_node_dll(doublylinklist* list, dllnode* node, dllnode* position)
{
	assert(list->length < UINT32_MAX);
	assert(list != NULL && node != NULL);
	
	
	if (position == list->head_dll)
	{
		node->right_ptr = list->head_dll;
		
		if (list->head_dll != NULL)         // special case when list is empty
		{
			list->head_dll->left_ptr = node;
		}

		list->head_dll = node;
		list->tail_dll = (list->tail_dll != NULL ? list->tail_dll : node);    // assign tail if list is empty
	}
	else if (position == list->tail_dll)
	{
		list->tail_dll->right_ptr = node;
		node->left_ptr = list->tail_dll;
		list->tail_dll = node;
	}
	else
	{
		node->right_ptr = position->right_ptr;
		position->right_ptr->left_ptr = node;
		node->left_ptr = position;
		position->right_ptr = node;
	}

	(list->length)++;
	return;
}

dllnode* remove_node_dll(doublylinklist* list, dllnode* position)
{
	assert(list != NULL && position != NULL);
	assert(list->length > 0);

	dllnode* temp = position;

	if (position == list->head_dll)
	{
		list->tail_dll = (list->tail_dll == list->head_dll ? NULL : list->tail_dll);

		list->head_dll = list->head_dll->right_ptr;
		list->head_dll->left_ptr = NULL;
		temp->right_ptr = NULL;
	}
	else if (position == list->tail_dll)
	{
		list->tail_dll = list->tail_dll->left_ptr;
		list->tail_dll->right_ptr = NULL;
		temp->left_ptr = NULL;
	}
	else
	{
		temp = position->right_ptr;
		position->right_ptr = temp->right_ptr;
		temp->right_ptr->left_ptr = position;
		temp->right_ptr = NULL;
		temp->left_ptr = NULL;
	}

	(list->length)--;
	return temp;
}

const dllnode* peek_node_dll(doublylinklist* list, dllnode* position)
{
	assert(list != NULL && list->head_dll != NULL && position != NULL);

	return position;
}

void destroy_dll(doublylinklist* list)
{
	assert(list != NULL && list->head_dll != NULL);
	
	dllnode* current_node = list->head_dll;

	list->head_dll = NULL;
	list->tail_dll = NULL;

	while (current_node)
	{
		dllnode* next_node = current_node->right_ptr;

		current_node->right_ptr = NULL;
		list->destructor(current_node);
		current_node = next_node;
	}

	free(list);
	list = NULL;
	return;
}