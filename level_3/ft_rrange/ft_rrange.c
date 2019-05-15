/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int i = 0;
    int *rrange;

    if (start > end)
        rrange = (int *)malloc(sizeof(int) * (start - end) + 1);
    else
        rrange = (int *)malloc(sizeof(int) * (end - start + 1));

    while (start != end)
    {
        rrange[i] = end;
        end -= (start > end ? -1 : 1);
        i++;
    }
    rrange[i] = end;
    return rrange;
}

// #include <stdio.h>
// int main()
// {
//     int *res = ft_rrange(1, 3);
//     printf("%d\n", res[0]);
//     printf("%d\n", res[1]);
//     printf("%d\n", res[2]);
//     // printf("%d\n", res[3]);
//     return 0;
// }