/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>  // printf
#include <stdlib.h> // atoi, malloc, free

void pgcd(int nb1, int nb2)
{
    int div;
    int pgcd;

    div = 1;
    if (nb1 <= 0 || nb2 <= 0)
        return;
    while (div <= nb1 || div <= nb2)
    {
        if (nb1 % div == 0 && nb2 % div == 0)
            pgcd = div;
        div++;
    }
    printf("%d", pgcd);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        pgcd(atoi(argv[1]), atoi(argv[2]));
    printf("\n");
    return (0);
}