/*
Assignment name  : rpn_calc
Expected files   : *.c, *.h 
Allowed functions: atoi, printf, write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string which contains an equation written in
Reverse Polish notation (RPN) as its first argument, evaluates the equation, and
prints the result on the standard output followed by a newline. 

Reverse Polish Notation is a mathematical notation in which every operator
follows all of its operands. In RPN, every operator encountered evaluates the
previous 2 operands, and the result of this operation then becomes the first of
the two operands for the subsequent operator. Operands and operators must be
spaced by at least one space.

You must implement the following operators : "+", "-", "*", "/", and "%".

If the string isn't valid or there isn't exactly one argument, you must print
"Error" on the standard output followed by a newline.

All the given operands must fit in a "int".

Examples of formulas converted in RPN:

3 + 4                   >>    3 4 +
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *

Here's how to evaluate a formula in RPN:

1 2 * 3 * 4 -
2 3 * 4 -
6 4 -
2

Or:

3 1 2 * * 4 -
3 2 * 4 -
6 4 -
2

Examples:

$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn_calc "1 2 3 4 +" | cat -e
Error$
$> ./rpn_calc |cat -e
Error$
*/

#include <stdio.h>
#include <stdlib.h>

#define IS_DIGIT(x) (x >= '0' || x <= '9') ? 1 : 0
#define IS_OPR(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%') ? 1 : 0
#define IS_SPACE(x) (x == ' ') ? 1 : 0

int do_math(int a, int b, char opr)
{
    switch (opr)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        return (a / b);
    case '%':
        return (a % b);
    default:
        break;
    }
    return (0);
}

void to_next(char **str)
{
    while (**str && !IS_SPACE(**str))
        (*str)++;
    if (**str)
        (*str)++;
}

int rpn_calc(char *str)
{
    int nums[2048] = {0};
    int i = -1;
    int a;
    int b;

    while (*str)
    {
        if (IS_OPR(*str))
        {
            if (i < 1)
                return (0);
            a = nums[i];
            i--;
            b = nums[i];
            nums[i] = do_math(a, b, *str);
        }
        else if (IS_DIGIT(*str))
        {
            i++;
            nums[i] = atoi(str);
        }
        to_next(&str);
    }
    if (i == 0)
    {
        printf("%d\n", nums[i]);
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2 || !rpn_calc(av[1]))
        printf("Error\n");
    return (0);
}