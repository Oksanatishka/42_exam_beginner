/*
Assignment name  : maff_alpha
Expected files   : maff_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the alphabet, with even letters in uppercase, and
odd letters in lowercase, followed by a newline.

Example:

$> ./maff_alpha | cat -e
aBcDeFgHiJkLmNoPqRsTuVwXyZ$
*/

#include <unistd.h>

int main()
{
    char even = 'a';
    char odd = 'B';
    int i = 0;
    while (i < 13)
    {
        write(1, &even, 1);
        write(1, &odd, 1);
        even += 2;
        odd += 2;
        i++;
    }
    write(1, "\n", 1);
    return 0;
}