/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int i = 0;
    t_list *ptr = begin_list;

    if (begin_list)
    {
        while (ptr)
        {
            ptr = ptr->next;
            i++;
        }
    }
    return i;
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     t_list *head = NULL;
//     t_list *second = NULL;
//     t_list *third = NULL;

//     // allocate 3 nodes in the heap
//     head = (t_list *)malloc(sizeof(t_list));
//     second = (t_list *)malloc(sizeof(t_list));
//     third = (t_list *)malloc(sizeof(t_list));

//     head->data = 1;
//     head->next = second;

//     second->data = 2;
//     second->next = third;

//     third->data = 3;
//     third->next = NULL;

//     int res = ft_list_size(head);
//     printf("%d\n", res);

//     return 0;
// }