/*
Assignment name  : options
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of arguments which could be 
considered as options and writes on standard output a representation of those
options as groups of bytes followed by a newline.

An option is an argument that begins by a '-' and have multiple characters 
which could be : abcdefghijklmnopqrstuvwxyz

All options are stocked in a single int and each options represents a bit of that
int, and should be stocked like this : 

00000000 00000000 00000000 00000000
******zy xwvutsrq ponmlkji hgfedcba

Launch the program without arguments or with the '-h' flag activated must print
an usage on the standard output, as shown in the following examples.

A wrong option must print "Invalid Option" followd by a newline.

Examples :
$>./options
options: abcdefghijklmnopqrstuvwxyz
$>./options -abc -ijk
00000000 00000000 00000111 00000111
$>./options -z
00000010 00000000 00000000 00000000
$>./options -abc -hijk
options: abcdefghijklmnopqrstuvwxyz
$>./options -%
Invalid Option

*/

#include <unistd.h>

#define DISPLAY_OPT write(1, "options: abcdefghijklmnopqrstuvwxyz", 35)
#define DISPLAY_INV write(1, "Invalid Option", 14)
#define IS_LOWER(x) (x >= 'a' && x <= 'z' ? 1 : 0)
#define SHIFTED(x) (1 << (x))

int options(int ac, char **av)
{
    int opt = 0;

    for (int i = 0; i < ac; i++)
        if (av[i][0] == '-')
            for (int k = 1; av[i][k]; k++)
            {
                if (!IS_LOWER(av[i][k]))
                    return (-1);
                opt |= SHIFTED(av[i][k] - 'a');
            }
    return (opt);
}

void print_int(int opt)
{
    if ((opt >> ('h' - 'a')) & 1)
        DISPLAY_OPT;
    else
        for (int i = 31; i >= 0; i--)
        {
            write(1, (((opt >> i) & 1) ? "1" : "0"), 1);
            if (i && !(i % 8))
                write(1, " ", 1);
        }
}

int main(int ac, char **av)
{
    int opt;
    if (ac > 1)
    {
        if ((opt = options(ac - 1, &av[1])) == -1)
            DISPLAY_INV;
        else
            print_int(opt);
    }
    else
        DISPLAY_OPT;
    write(1, "\n", 1);
    return (0);
}
