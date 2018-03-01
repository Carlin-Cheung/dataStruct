#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"


status init_sqlist(sqlist *L)
{
	//L->elem_array = (elem_type *)malloc(MAXSIZE * sizeof(elem_type));
	//if(!L->elem_array) return ERROR;
	int i;
	for(i = 0; i < MAXSIZE; ++i)
		L->elem_array[i] = 0;
	L->sqlength = 0;
	return OK;
}

status insert_sqlist(sqlist *L, int i, elem_type e)
{
	int j;
	if(i < 0 || i > L->sqlength)
	{
		printf("the insert location error\n");
		return ERROR;
	}
	if(L->sqlength >= MAXSIZE)
	{
		printf("the sqlist over\n");
		return ERROR;
	}
	for(j = L->sqlength; j>i; --j)
	{
		L->elem_array[j] = L->elem_array[j-1];
	}
	L->elem_array[i] = e;
	++L->sqlength;
	return OK;

}

elem_type delete_sqlist(sqlist *L, int i)
{
	int j;

	elem_type e = L->elem_array[i];
	if(i < 0 || i > L->sqlength - 1) return ERROR;
	for(j = i + 1; j < L->sqlength; ++j)
	{
		L->elem_array[j - 1] = L->elem_array[j];
	}
	--L->sqlength;
	return e;
}

status locate_delete_sqlist(sqlist *L, elem_type x)
{
	int i, j=0;

	for(i = 0; i < L->sqlength; ++i)
	{
		if(L->elem_array[i] == x)
		{
			j = i;
			break;
		}
	}
	if(i >= L->sqlength) return ERROR;
	delete_sqlist(L, j);
	return OK;
}
