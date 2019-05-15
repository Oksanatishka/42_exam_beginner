/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

/*
** 1. ft_strlen
** 2. ft_isspace
** 3. expand_str
*/

#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' ? 1 : 0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int len = ft_strlen(argv[1]) - 1;
        while (ft_isspace(argv[1][i]))
        {
            i++;
        }
        while (ft_isspace(argv[1][len]))
        {
            len--;
        }
        while (i <= len)
        {
            if (ft_isspace(argv[1][i]))
            {
                while (ft_isspace(argv[1][i]))
                {
                    i++;
                }
                write(1, "   ", 3);
            }
            if (argv[1][i] && !ft_isspace(argv[1][i]))
            {
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);

    return 0;
}