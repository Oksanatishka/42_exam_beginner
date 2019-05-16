/*
Assignment name  : check_mate 
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program who takes rows of a chessboard in argument and check if your 
King is in a check position.

Chess is played on a chessboard, a squared board of 8-squares length with 
specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
and obviously a King.

Each piece have a specific method of movement, and all patterns of capture are
detailled in the examples.txt file.

A piece can capture only the first ennemy piece it founds on its capture
patterns.

The board have a variable size but will remains a square. There's only one King
and all other pieces are against it. All other characters except those used for
pieces are considered as empty squares.

The King is considered as in a check position when an other enemy piece can
capture it. When it's the case, you will print "Success" on the standard output
followed by a newline, otherwise you will print "Fail" followed by a newline.

If there is no arguments, the program will only print a newline.

Examples:

$> ./chessmate '..' '.K' | cat -e
Fail$
$> ./check_mate 'R...' '.K..' '..P.' '....' | cat -e
Success$
$> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
Success$
$> ./chessmate | cat -e
$
$>

*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

char *ft_strcpy(char *dst, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char **create_tab(int len, char **argv)
{
    char **tab;
    int i;

    i = 1;
    if (!(tab = (char **)malloc(sizeof(char *) * len + 1)))
        return (NULL);
    tab[len] = NULL;
    while (i < len + 1)
    {
        if (!(tab[i - 1] = (char *)malloc(sizeof(char) * len + 1)))
            return (NULL);
        tab[i - 1][len] = '\0';
        tab[i - 1] = ft_strcpy(tab[i - 1], argv[i]);
        i++;
    }
    return (tab);
}

int check_rook(char **tab, int y, int x)
{
    int i;
    int j;

    j = x + 1;

    while (tab[y][j] != '\0')
    {
        if (tab[y][j] == 'P' || tab[y][j] == 'B' || tab[y][j] == 'Q' || tab[y][j] == 'R')
            return (0);
        if (tab[y][j] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        j++;
    }

    j = x - 1;

    while (j >= 0)
    {
        if (tab[y][j] == 'P' || tab[y][j] == 'B' || tab[y][j] == 'Q' || tab[y][j] == 'R')
            return (0);
        if (tab[y][j] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        j--;
    }

    i = y + 1;

    while (tab[i] != NULL)
    {
        if (tab[i][x] == 'P' || tab[i][x] == 'B' || tab[i][x] == 'Q' || tab[i][x] == 'R')
            return (0);
        if (tab[i][x] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        i++;
    }
    i = y - 1;

    while (i >= 0)
    {
        if (tab[i][x] == 'P' || tab[i][x] == 'B' || tab[i][x] == 'Q' || tab[i][x] == 'R')
            return (0);
        if (tab[i][x] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        i--;
    }
    return (0);
}

int check_pawn(char **tab, int y, int x)
{
    if (y > 0 && (tab[y - 1][x - 1] == 'K' || tab[y - 1][x + 1] == 'K'))
    {
        ft_putstr("Success\n");
        return (1);
    }
    return (0);
}

int check_bishop(char **tab, int y, int x)
{
    int i;
    int j;

    i = y + 1;
    j = x + 1;

    while (tab[i] != NULL)
    {
        if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
            return (0);
        if (tab[i][j] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        i++;
        j++;
    }
    i = y + 1;
    j = x - 1;

    while (tab[i] != NULL)
    {
        if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
            return (0);
        if (tab[i][j] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        i++;
        j--;
    }
    i = y - 1;
    j = x + 1;

    while (i >= 0)
    {
        if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
            return (0);
        if (tab[i][j] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        i--;
        j++;
    }
    i = y - 1;
    j = x - 1;

    while (i >= 0)
    {
        if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
            return (0);
        if (tab[i][j] == 'K')
        {
            ft_putstr("Success\n");
            return (1);
        }
        i--;
        j--;
    }
    return (0);
}

int check_queen(char **tab, int i, int j)
{
    if (check_bishop(tab, i, j) == 1)
        return (1);
    if (check_rook(tab, i, j) == 1)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    char **tab;
    int i = 0;
    int j = 0;
    if (argc > 1)
    {
        tab = create_tab(argc - 1, argv);
        if (tab == NULL)
            return (-1);
        while (tab[i] != NULL)
        {
            // printf("tab[i] : %s\n", tab[i]);
            i++;
        }
        i = 0;
        while (tab[i] != NULL)
        {
            j = 0;
            while (tab[i][j] != '\0')
            {
                if (tab[i][j] == 'R')
                {
                    if (check_rook(tab, i, j) == 1)
                        return (0);
                }
                else if (tab[i][j] == 'P')
                {
                    if (check_pawn(tab, i, j) == 1)
                        return (0);
                }
                else if (tab[i][j] == 'B')
                {
                    if (check_bishop(tab, i, j) == 1)
                        return (0);
                }
                else if (tab[i][j] == 'Q')
                {
                    if (check_queen(tab, i, j) == 1)
                        return (0);
                }
                j++;
            }
            i++;
        }
        ft_putstr("Fail");
        free(*tab);
    }
    ft_putstr("\n");
    return (0);
}