/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet){
    int oct = octet;
    int div = 128;

    while(div != 0){
        if(div <= oct){
            write(1,"1", 1);
            oct = oct % div;
        } else {
            write(1,"0", 1);
        }
        div = div /2;
    }
}

int main(){
    print_bits(2);
    return 0;
}