/*
Assignment name  : hello
Expected files   : hello.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays "Hello World!" followed by a \n.

Example:

$>./hello
Hello World!
$>./hello | cat -e
Hello World!$
$>
*/

#include <unistd.h>

int main(){
    // char *myString = "Hello World!";
    // int i=0;
    // while(myString[i] != '\0'){
    //     write(1, &myString[i],1);
    //     i++;
    // }
    // write(1,"\n",1);
    write(1,"Hello World!\n",13);
    return 0;
}