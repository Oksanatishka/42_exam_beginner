/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
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
    return (c == ' ' || c == '\t' ? 1 : 0); // || c == '\n' || c == '\v' || c == '\f' || c == '\r'
}

void epur_str(char *str)
{
    int i = 0;
    int len = ft_strlen(str) - 1;

    // no spaces at the beginning
    while (ft_isspace(str[i]))
    {
        i++;
    }
    // no spaces at the end
    while (ft_isspace(str[len]))
    {
        len--;
    }
    while (i <= len)
    {
        if (ft_isspace(str[i]))
        {
            while (ft_isspace(str[i]))
            {
                i++;
            }
            write(1, " ", 1);
        }
        if (str[i] && !ft_isspace(str[i]))
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        epur_str(argv[1]);
    }
    write(1, "\n", 1);
    return 0;
}