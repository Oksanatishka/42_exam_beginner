/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

int convertStrToInt(char *str){ // atoi
    int i=0;
    int num =0;
    int sign = 1;

    
    if(!str[i])
        return 0;
    
    while(str[i] == ' ' || str[i] == '\t' ||str[i] == '\n' ||str[i] == '\f' || str[i] == '\v' ||str[i] == '\r')
        i++;
    
    if (str[i] == '-' || str[i] == '+'){
		if (str[i++] == '-')
			sign = -1;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (num * sign);
}

void printNum(int n){
    char ch;
    if(n <0){
        n = -n;
        ft_putchar('-');
    }
    if(n< 10){
        ch = n + '0';
        ft_putchar(ch);
    } else {
        printNum(n /10);
        printNum(n % 10);
    }
}

int isPrime(int num){
    int i=2;
    if(num <= 1){
        return 0;
    }
    while(i <= (num/2)){
        if(num % i == 0){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char **argv){
    if(argc ==2 ){
        int sum = 0;
        int myNum = convertStrToInt(argv[1]);
        while(myNum > 0){
            if(isPrime(myNum)){
                sum += myNum;
            } 
            myNum--; 
        } 
        printNum(sum);
    } else {
        ft_putchar('0');
    }
    ft_putchar('\n');
    return 0;
}