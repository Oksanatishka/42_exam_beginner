/*
Assignment name  : maff_revalpha
Expected files   : maff_revalpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the alphabet in reverse, with even letters in
uppercase, and odd letters in lowercase, followed by a newline.

Example:

$> ./maff_revalpha | cat -e
zYxWvUtSrQpOnMlKjIhGfEdCbA$
*/

#include <unistd.h>

int main()
{
    char odd = 'z';
    char even = 'Y';
    int i = 0;

    while (i < 13)
    {
        write(1, &odd, 1);
        write(1, &even, 1);
        odd -= 2;
        even -= 2;
        i++;
    }
    write(1, "\n", 1);
    return 0;
}