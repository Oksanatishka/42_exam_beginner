/*
Assignment name  : ft_itoa_base
Expected files   : ft_itoa_base.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that converts an integer value to a null-terminated string
using the specified base and stores the result in a char array that you must
allocate.

The base is expressed as an integer, from 2 to 16. The characters comprising
the base are the digits from 0 to 9, followed by uppercase letter from A to F.

For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".

If base is 10 and value is negative, the resulting string is preceded with a
minus sign (-). With any other base, value is always considered unsigned.

Your function must be declared as follows:

char	*ft_itoa_base(int value, int base);
*/

#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

char *ft_strrev(char *s)
{
    int i = 0;
    int k = ft_strlen(s) - 1;

    while (i < k)
    {
        s[i] ^= s[k];
        s[k] ^= s[i];
        s[i] ^= s[k];
        i++;
        k--;
    }
    return (s);
}

char *ft_itoa_base(int value, int base)
{
    char *hex = "0123456789ABCDEF";
    char *total = (char *)malloc(13);
    int i = 0;
    int n = 1;

    if (!value)
    {
        total[0] = '0';
        total[1] = '\0';
        return (total);
    }
    if (value < 0)
        n = -1;
    while (value)
    {
        total[i] = hex[(value * n) % base];
        value /= base;
        i++;
    }
    if (n == -1 && base == 10)
    {
        total[i] = '-';
        i++;
    }
    total[i] = '\0';
    return (ft_strrev(total));
}