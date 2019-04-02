/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <unistd.h>

void ft_putchar(char c){
    write(1,&c,1);
}
int main(int argc, char **argv){
    if(argc ==2){
        int i=0;
        while(argv[1][i]!= '\0'){
            int shiftOfLetter;
            if(argv[1][i] >='a' && argv[1][i]<='z'){
                shiftOfLetter = 'z' - (argv[1][i] - 'a');
                ft_putchar(shiftOfLetter);
            } else if(argv[1][i] >='A' && argv[1][i]<='Z'){
                shiftOfLetter = 'Z' - (argv[1][i] - 'A');
                ft_putchar(shiftOfLetter);
            } else {
                ft_putchar(argv[1][i]);
            }
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}