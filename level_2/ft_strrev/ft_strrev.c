/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdlib.h>
#include <stdio.h>

char    *ft_strrev(char *str){
    int len=0;
    int i=0;
    char temp;

    while(str[len] != '\0')
        len++;
    // printf("%d", len);
    while(i<len-1 ){    
        temp = str[i];
        str[i] = str[len-1];
        str[len-1] = temp;
        i++;
        len--;
    }
    
    return str;
}
int main(){
    char myStr[30] = "String abc.";
    printf("%s", ft_strrev(myStr));
    return 0;
}

// str[0] -> str[10]
// str[1] -> str[9]
// str[2] -> str[8]
// str[3] -> str[7]
// str[4] -> str[6]
