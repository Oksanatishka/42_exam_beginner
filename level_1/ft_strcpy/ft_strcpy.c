/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/
#include <stdio.h>
// #include <string.h>

char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    // don't forget to add 'end of line'
    s1[i] = '\0';
    return s1;
}

// int main()
// {
//     char dest[50];
//     char *myString = "Another string here.";
//     printf("%s", ft_strcpy(dest, myString));
//     printf("%s", strcpy(dest, myString));
//     return 0;
// }
