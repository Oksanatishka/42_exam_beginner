/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

// #include <unistd.h>

// #define IS_DIGIT(x) (x >= '0' && x <= '9') ? 1 : 0

// int ft_atoi(char *s)
// {
//     int n;

//     n = 0;
//     while (*s && IS_DIGIT(*s))
//     {
//         n *= 10;
//         n += ((*s) - 48);
//         s++;
//     }
//     return (n);
// }

// void print_from(char *t, int i)
// {
//     while (t[i])
//         write(1, &t[i++], 1);
// }

// void print_hex(int n)
// {
//     char *hex = "0123456789abcdef";
//     char tmp[15] = {0};
//     int i = 13;

//     if (!n)
//         write(1, "0", 1);
//     while (n)
//     {
//         tmp[i] = hex[n % 16];
//         n /= 16;
//         i--;
//     }
//     print_from(tmp, ++i);
// }

// int main(int ac, char **av)
// {
//     if (ac == 2)
//         print_hex(ft_atoi(av[1]));
//     write(1, "\n", 1);
//     return (0);
// }

#include <unistd.h>

int ft_atoi(char *s)
{
    long r;
    int sign;

    while (*s == 32 || (*s >= 9 && *s <= 13))
        s++;
    sign = (*s == '-') ? -1 : 1;
    (*s == '-' || *s == '+') ? s++ : s;
    r = 0;
    while (*s >= '0' && *s <= '9')
        r = r * 10 + *s++ - '0';
    return ((int)r * sign);
}

void print_hex(int n)
{
    if (n >= 16)
        print_hex(n / 16);
    n = n % 16;
    n += n < 10 ? '0' : 'a' - 10;
    write(1, &n, 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        print_hex(ft_atoi(av[1]));
    write(1, "\n", 1);
    return (1);
}