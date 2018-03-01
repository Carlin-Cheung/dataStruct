#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
#include "list.h"

/**
int main()
{
    int i;
    sqlist *L = (sqlist *)malloc(sizeof(sqlist));
    init_sqlist(L);
    for(i = 0; i < 10; ++i)
	{
		insert_sqlist(L,i,i);
	}

    for(i = 0; i < 10; ++i)
	{
		printf("%d,",L->elem_array[i]);
	}
    return 0;
}
*/

listNode* merge_list_test()
{
	listNode *La, *Lb;
	La = create_list_end_insert();
	Lb = create_list_end_insert();
	return merge_list_sorted(La, Lb);
}

int main()
{
	int i;
	listNode *L = NULL, *Lc;
	listNode *p;
	listNode *result;
	//L = create_list_front_insert();
	L = create_list_end_insert();
	p = L->next;
	while(p != NULL)
	{
		printf("%d, ", p->element);
		p = p ->next;
	}
	printf("\n");
	for(i = 1; i <= L->element; ++i)
	{
		printf("%d, ", get_elem_location(L,i));
	}
	printf("\n");

	result = get_elem_value(L, 4);
	if(result != NULL)
	{
		printf("%d\n", result->element);
	}else
	{
		printf("not exist!\n");
	}

	insert_listNode(L, 5, 100);

	for(i = 1; i <= L->element; ++i)
	{
		printf("%d, ", get_elem_location(L,i));
	}
	printf("\n");
	/**
	delete_listNode_location(L, 0);

	for(i = 1; i <= L->element; ++i)
	{
		printf("%d, ", get_elem_location(L,i));
	}
	printf("\n");

	delete_listNode_value(L, 2);

	for(i = 1; i <= L->element; ++i)
	{
		printf("%d, ", get_elem_location(L,i));
	}
	printf("\n");


	delete_listNode_value_all(L, 2);
	p = L->next;
	while(p != NULL)
	{
		printf("%d, ", p->element);
		p = p ->next;
	}
	printf("\n");
	*/

	delete_listNode_value_all_repli(L);
	p = L->next;
	while(p != NULL)
	{
		printf("%d, ", p->element);
		p = p ->next;
	}
	printf("\n");


	Lc = merge_list_test();
	p = Lc->next;
	while(p != NULL)
	{
		printf("%d, ", p->element);
		p = p ->next;
	}
	printf("\n");
	return 0;
}
