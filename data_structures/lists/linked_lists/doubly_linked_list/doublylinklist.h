#ifndef DOUBLY_LL
#define DOUBLY_LL

#include "../header_to_include/std_dsa_lib.h"

typedef struct dllnode
{
	void* data;
	struct dllnode* left_ptr, * right_ptr;
}	dllnode;

typedef struct doublylinklist
{
	dllnode* head_dll;
	dllnode* tail_dll;
	uint32_t length;

	void (*destructor)(dllnode*);
}	doublylinklist;

doublylinklist* init_dll(void (*destroy)(dllnode*));

dllnode* init_dllnode(const void* data);

void insert_node_dll(doublylinklist* list, dllnode* node_to_insert, dllnode* head_tail_or_insert_after);

dllnode* remove_node_dll(doublylinklist* list, dllnode* head_tail_or_remove_after);

const dllnode* peek_node_dll(doublylinklist* list, dllnode* peek_at);

void destroy_dll(doublylinklist* list);

#endif