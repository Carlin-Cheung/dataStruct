#include <stdio.h>
#include <stdlib.h>
#include "list.h"

listNode* create_list_front_insert(void)
{
	listNode *head = (listNode *)malloc(sizeof(listNode));
	listNode *p;
	elem_type data = 0;

	head->element = 0;
	head->next = NULL;

	while(1)
	{
		scanf("%d", &data);
		if (data==32767)  break ;
		p = (listNode *)malloc(sizeof(listNode));
		p->element = data;
		p->next = head->next;
		head->next = p;
		++head->element;
	}
    return head;
}

listNode* create_list_end_insert(void)
{
	listNode *head = (listNode *)malloc(sizeof(listNode));
	listNode *p, *q=head;
	elem_type data = 0;

	head->element = 0;
	head->next = NULL;

	while(1)
	{
		scanf("%d", &data);
		if (data==32767)  break ;
		p = (listNode *)malloc(sizeof(listNode));
		p->element = data;
		q->next = p;
		q = p;
		p->next = NULL;
		++head->element;
	}
    return head;
}

elem_type get_elem_location(listNode *L, int i)
{
	int j = 1;
	listNode *p = L->next;

	if(i <= 0 || i > L->element) return -32768;
	while(j < i)
	{
		p = p->next;		++j;
	}
	if(j != i) return ERROR;
	return p->element;
}

listNode* get_elem_value(listNode *L, elem_type key)
{
	listNode *p = L->next;

	while(p != NULL && p->element != key)
			p = p->next;
	if(p == NULL) return NULL;
	return p;

}

status insert_listNode(listNode *L, int i, elem_type e)
{
	listNode *p, *q;
	int j = 1;
	p = L;
	if(i > L->element) return ERROR;
	while(p != NULL && j < i)
	{
		p = p->next;
		++j;
	}
	if(j != i)
	{
		printf("i error\n");
		return ERROR;
	}
	else
	{
		q = (listNode *)malloc(sizeof(listNode));
		q->element = e;
		q->next = p->next;
		p->next = q;
		++L->element;
		return OK;	}

}

listNode* delete_listNode_location(listNode *L, int i)
{
	listNode *p, *q;
	int j = 1;
	p = L;
	while(p != NULL && j < i)
	{
		p = p->next;
		++j;
	}
	if(j != i)
	{
		printf("i error\n");
		return NULL;	}
	else
	{
		q = p->next;
		p->next = q->next;
		--L->element;
		return q;	}
}

status delete_listNode_value(listNode *L, elem_type key)
{
	listNode *p, *q;
	q = L;
	p = L->next;
	while(p != NULL && p->element != key)
	{
		q = p;
		p = p->next;
	}
	if(p == NULL)
	{
		printf("key error\n");
		return ERROR;	}else
	{
		q->next = p->next;
		free(p);
		--L->element;
		return OK;	}
}

void delete_listNode_value_all(listNode *L, elem_type key)
{
	listNode *p, *q;
	q = L;
	p = L->next;
	while(p != NULL)
	{
		if(p->element != key)
		{
			q = p;
			p = p ->next;
		}else
		{
			q->next = p->next;
			free(p);
			p = q->next;
		}
	}

}

void delete_listNode_value_all_repli(listNode *L)
{
	listNode *p;
	p = L->next;
	elem_type elem;
	while(p != NULL)
	{
		elem = p->element;
		delete_listNode_value_all(p, elem);
		p = p->next;
	}
}

listNode * merge_list_sorted(listNode *La, listNode *Lb)
{
	listNode *qa, *qb, *Lc, *qc;
	qa = La->next;
	qb = Lb->next;
	Lc = qc = La;
	while(qa != NULL && qb != NULL)
	{
		if(qa->element <= qb->element)
		{
			qc->next = qa;
			qa = qa->next;
		}else
		{
			qc->next = qb;
			qb = qb->next;
		}
		qc = qc->next;
	}

	if(qa == NULL)
	{
		qc->next = qb;
	}
	if(qb == NULL)
	{
		qc->next = qa;
	}
	Lc->element = La->element + Lb->element;
	free(Lb);
	return Lc;
}
