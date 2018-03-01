#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define OK 1
#define ERROR -1

typedef int status;
typedef int elem_type;

typedef struct listNode
{
	elem_type element;
	struct listNode *next;
}listNode;

listNode* create_list_front_insert(void);

listNode* create_list_end_insert(void);

elem_type get_elem_location(listNode *L, int i);

listNode* get_elem_value(listNode *L, elem_type key);

status insert_listNode(listNode *L, int i, elem_type e);

listNode* delete_listNode_location(listNode *L, int i);

status delete_listNode_value(listNode *L, elem_type key);

void delete_listNode_value_all(listNode *L, elem_type key);

void delete_listNode_value_all_repli(listNode *L);

listNode * merge_list_sorted(listNode *La, listNode *Lb);

#endif // LIST_H_INCLUDED
