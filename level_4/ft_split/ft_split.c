/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

char **ft_split(char *str)
{
    int i = 0;
    int j;
    int k = 0;
    char **split;

    if (!(split = (char **)malloc(sizeof(char *) * 256)))
        return (NULL);
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    while (str[i])
    {
        j = 0;
        if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
            return (NULL);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
            split[k][j++] = str[i++];
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i += 1;
        split[k][j] = '\0';
        k += 1;
    }
    split[k] = NULL;
    return (split);
}

// #include <stdio.h>

// int main(int ac, char **av)
// {
//     char *phrase = "   Hello,   Flavio\t Wuensche!  ";
//     char **arr = ft_split(phrase);
//     printf("%s\n", arr[0]);
//     printf("%s\n", arr[1]);
//     printf("%s\n", arr[2]);
//     printf("%s\n", arr[3]);
// }