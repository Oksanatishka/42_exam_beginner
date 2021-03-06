/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2){
    int i=0;
    while(s1[i] && s2[i]){
        if(s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

int main(){
    char *str1 = "String one";
    char *str2 = "Ktring one";

    printf("%d", ft_strcmp(str1,str2));
    // printf("%d", strcmp(str1,str2));
    return 0;
}