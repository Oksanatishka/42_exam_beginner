/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdio.h>
// #include <string.h>
#include <stdlib.h>

char    *ft_strdup(char *src){
    char *result;
    int i=0;
    int len = 0;
    
    while(src[len] != '\0'){
        len++;
    }
    result = (char *)malloc(sizeof(*result) * (len +1));
    while(i<len){
        result[i] = src[i];
        i++;
    }
    return result;
}

int main(){
    char *str = "My String.";
    printf("%s", ft_strdup(str));
    // printf("%s", strdup(str));
    return 0;
}