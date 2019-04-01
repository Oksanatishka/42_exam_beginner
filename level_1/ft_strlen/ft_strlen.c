/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
*/

#include <stdio.h>
// #include <string.h>

int	ft_strlen(char *str){
    int length = 0;
    int i=0;
    while(str[i] !='\0'){
        length +=1;
        i++;
    }
    return length;
}
// int main(){
//     printf("%d", ft_strlen("This is string."));
//     printf("%lu", strlen("This is string."));
//     return 0;
// }