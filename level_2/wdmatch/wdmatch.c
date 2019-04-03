/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

// int main(int argc, char **argv){
//     if(argc==3){
//         int i =0;
//         int j= 0;
        
//         int len = 0;

//         while(argv[1][len]){
//             len++;
//         }
//         char *result[len];

//         while(argv[1][i]){
//             while(argv[2][j]){
//                 if(argv[1][i] == argv[2][j]){
//                     result[i] = argv[1][i];
//                 }
//                 j++;
//             }
//             i++;
//         }
//         i = 0;
//         while(i<len){
//             if(result[i] != argv[1][i] ){
//                 write(1,"\n",1);
//                 return 0;
//             }
//         }
//         i = 0;
//         while(i<len){
//             write(1,result[i],1);
//             i++;
//         }
    
//         return 0;
//     }
//     write(1,"\n",1);
//     return 0;
// }