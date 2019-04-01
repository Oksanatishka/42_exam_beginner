/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

void ft_putchar(char c){
    write(1,&c,1);
}
int main(int argc, char **argv){
    if(argc==2){
        int i=0;
        while(argv[1][i] != '\0'){
            
            if((argv[1][i] >='a' && argv[1][i] <= 'y')|| (argv[1][i] >='A' && argv[1][i] <= 'Y')){
                ft_putchar(argv[1][i]+1);
            } else if(argv[1][i] =='z'){
                ft_putchar('a');
            } else if(argv[1][i] =='Z'){
                ft_putchar('A');
            } else {
                ft_putchar(argv[1][i]);
            }
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}