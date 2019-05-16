/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function 
pointer cmp to select the order to apply, and returns a pointer to the 
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h 
that is provided to you. You must include that file 
(#include "list.h"), but you must not turn it in. We will use our own 
to compile your assignment.

Functions passed as cmp will always return a value different from 
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list 
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/

#include "list.h"

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int ascending(int a, int b)
{
	return (a <= b);
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *begin;
	t_list *p;

	begin = lst;
	while (lst)
	{
		p = lst->next;
		while (p)
		{
			if (!(*cmp)(lst->data, p->data))
			{
				swap(&lst->data, &p->data);
			}
			p = p->next;
		}
		lst = lst->next;
	}
	return (begin);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
// 	t_list *l;
// 	int i;
// 	t_list *t;
// 	t_list *b;

// 	i = 50;
// 	l = malloc(sizeof(t_list));
// 	t = l;
// 	b = l;
// 	while (i)
// 	{
// 		l->data = i % 3;
// 		l->next = malloc(sizeof(t_list));
// 		l = l->next;
// 		--i;
// 	}
// 	l->data = (int)"fromage";
// 	l->next = NULL;
// 	while (t)
// 	{
// 		printf("%d ", t->data);
// 		t = t->next;
// 		++i;
// 	}
// 	b = sort_list(b, ascending);
// 	while (b)
// 	{
// 		printf("%d ", b->data);
// 		b = b->next;
// 		++i;
// 	}
// }