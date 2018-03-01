#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#define OK 1
#define ERROR -1
#define MAXSIZE 100

typedef int status;
typedef int elem_type;

typedef struct sqlist {
	elem_type elem_array[MAXSIZE];
	int sqlength;
}sqlist;

status init_sqlist(sqlist *L);

status insert_sqlist(sqlist *L, int i, elem_type e);

elem_type delete_sqlist(sqlist *L, int i);

status locate_delete_sqlist(sqlist *L, elem_type x);

#endif // SQLIST_H_INCLUDED
