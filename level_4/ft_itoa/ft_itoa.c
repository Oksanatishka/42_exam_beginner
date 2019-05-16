/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

static int ft_strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

static char *ft_strrev(char *str)
{
    int i;
    int j;
    int tmp;

    i = 0;
    j = ft_strlen(str);
    while (j > i)
    {
        j--;
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
    }
    return str;
}

char *ft_itoa(int nbr)
{
    int i;
    int neg;
    char *tmp;

    i = 0;
    neg = 0;
    tmp = malloc(sizeof(char) * 12);
    if (tmp == NULL || nbr == 0)
        return ((nbr == 0) ? "0" : NULL);
    if (nbr == -2147483648)
        return ("-2147483648");
    if (nbr < 0)
    {
        neg = 1;
        nbr *= -1;
    }
    while (nbr)
    {
        tmp[i++] = (nbr % 10) + '0';
        nbr /= 10;
    }
    if (neg)
        tmp[i] = '-';
    return ft_strrev(tmp);
}

// #include <stdio.h>
// int main(void)
// {
//     int i = 0;
//     int tab[5] = {-2147483648, -42, 0, 42, 2147483647};

//     while (i < 5)
//         printf("%s\n", ft_itoa(tab[i++]));

//     return 0;
// }