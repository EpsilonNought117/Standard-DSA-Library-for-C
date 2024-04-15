#ifndef SINGLY_LL
#define SINGLY_LL

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>

typedef struct sllnode
{
	void* node_data;
	struct sllnode* next_ptr;
}	sllnode;

typedef struct singlylinklist
{
	sllnode* head_sll;
	sllnode* tail_sll;
	uint32_t length;

	void (*destructor)(sllnode*);  // to destroy a node of the list, not list itself
}	singlylinklist;

singlylinklist* init_sll(void (*destroy)(sllnode*));

sllnode* init_sllnode(const void* data);

void insert_node_sll(singlylinklist* list, sllnode* node_to_insert, sllnode* head_tail_OR_insert_after);

sllnode* remove_node_sll(singlylinklist* list, sllnode* head_tail_or_remove_after); // takes list->head_sll or node of position to remove at next

const sllnode* peek_node_sll(singlylinklist* list, sllnode* peek_at);

void destroy_sll(singlylinklist* list);

#endif