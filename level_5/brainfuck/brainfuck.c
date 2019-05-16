/*
Assignment name  : brainfuck
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a Brainfuck interpreter program.
The source code will be given as first parameter.
The code will always be valid, with no more than 4096 operations.
Brainfuck is a minimalist language. It consists of an array of bytes 
(in our case, let's say 2048 bytes) initialized to zero, 
and a pointer to its first byte.

Every operator consists of a single character :
- '>' increment the pointer ;
- '<' decrement the pointer ;
- '+' increment the pointed byte ;
- '-' decrement the pointed byte ;
- '.' print the pointed byte on standard output ;
- '[' go to the matching ']' if the pointed byte is 0 (while start) ;
- ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

Examples:

$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
Hi$
$>./brainfuck | cat -e
$
*/

#include <unistd.h>

void brainfuck(char *s)
{
    char arr[2048] = {0};
    char *p = &arr[0];
    int depth = 0;

    while (*s)
    {
        switch (*s)
        {
        case '>':
            p++;
            break;
        case '<':
            p--;
            break;
        case '+':
            (*p)++;
            break;
        case '-':
            (*p)--;
            break;
        case '.':
            write(1, p, 1);
            break;
        case '[':
            if (!*p)
            {
                depth = 1;
                while (depth)
                {
                    s++;
                    if (*s == '[')
                        depth++;
                    else if (*s == ']')
                        depth--;
                }
            }
            break;
        case ']':
            if (*p)
            {
                depth = 1;
                while (depth)
                {
                    s--;
                    if (*s == ']')
                        depth++;
                    else if (*s == '[')
                        depth--;
                }
            }
            break;
        default:
            break;
        }
        s++;
    }
}

int main(int ac, char **av)
{
    ac > 1 ? brainfuck(av[1]) : write(1, "\n", 1);
    return (0);
}