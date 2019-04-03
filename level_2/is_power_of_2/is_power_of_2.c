/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int is_power_of_2(unsigned int n);
*/

// https://stackoverflow.com/questions/108318/whats-the-simplest-way-to-test-whether-a-number-is-a-power-of-2-in-c

#include <stdio.h>

int is_power_of_2(unsigned int n){
    
    if(n%2 == 0){
        int num=2;
        while(num <= n){
            if(num == n){
                return 1;
            }
            num +=2;
        }
    }
    return 0;
}
int main(){
    printf("%d", is_power_of_2(7));
    return 0;
}
