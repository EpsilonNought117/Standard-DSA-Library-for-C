#ifndef SINGLY_LL
#define SINGLY_LL

typedef struct sllnode
{
	void* node_data;
	struct sllnode* next_ptr;
}	sllnode;

typedef struct singlylinklist
{
	sllnode* head_sll;
	sllnode* tail_sll;
	uint32_t elements;

	void (*destructor)(sllnode*);
}	singlylinklist;

singlylinklist* init_sll(void (*destroy)(void**));

sllnode* init_node_sll(const void* data);

void insert_at_head(singlylinklist* list, const sllnode* node);

void insert_at_tail(singlylinklist* list, const sllnode* node);

void insert_at_position(singlylinklist* list, const sllnode* node, const void* position);

void* remove_at_head(singlylinklist* list);

void* remove_at_position(singlylinklist* list, const void* position);

const void* check_head(singlylinklist* list);

const void* check_tail(singlylinklist* list);

const void* check_at_pos(singlylinklist* list, const void* position);

void destroy_sll(singlylinklist* list);

#endif