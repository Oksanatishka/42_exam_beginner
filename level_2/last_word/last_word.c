/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
#include <unistd.h>

int main(int argc, char **argv){
    int indexOfLastWord = 0;
    int len = 0;
    if(argc==2){
        while(argv[1][len] != '\0'){
            if(argv[1][len] == ' ' && argv[1][len+1] >=33 && argv[1][len+1] <=127 ){
                indexOfLastWord = len+1;
            }
            len++;
        }
        while(argv[1][indexOfLastWord] >=33 && argv[1][indexOfLastWord] <=127){
            write(1, &argv[1][indexOfLastWord],1);
            indexOfLastWord++;
        }
    }
    write(1,"\n",1);
    return 0;
}