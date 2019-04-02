/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

// #include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str){
    int res = 0;
    int negativeNumber = 1;

    if(*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' )){
        ++str;
    }

    if(*str == '-'){
        negativeNumber = -1;
    }
    if(*str == '-' || *str == '+'){
        ++str;
    }

    while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}

    return res * negativeNumber;
}

int main(){
    char *myStr = "43";
    printf("%d", ft_atoi(myStr));
    // printf("%d", atoi(myStr));

    return 0;
}