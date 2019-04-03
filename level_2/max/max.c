/*
Assignment name  : max
Expected files   : max.c
Allowed functions: 
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <stdio.h>

int		max(int* tab, unsigned int len) {
    unsigned int i = 0;
    int max = tab[0];

    while(i < len){
        if(tab[i] > max){
            max = tab[i];
        }
        i++;
    }
    return max;
}

int main(){
    int numbers[5] = {1,2,5,10, 4};
    printf("%d", max(numbers, 5));
    return 0;
}