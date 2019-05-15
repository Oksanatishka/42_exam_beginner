/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

// int ft_ishex(char c)
// {
//     return ((c >= '0' && c <= '9') ||
//                     (c >= 'a' && c <= 'f') ||
//                     (c >= 'A' && c <= 'F')
//                 ? 1
//                 : 0);
// }

// int ft_baseten(char c)
// {
//     if (c >= 'A' && c <= 'F')
//         return (c - 54);
//     if (c >= 'a' && c <= 'f')
//         return (c - 86);
//     if (c >= '0' && c <= '9')
//         return (c - 48);
// }

// int ft_atoi_base(const char *str, int str_base)
// {
//     int i;
//     int n;
//     int sign;

//     n = 0;
//     sign = (str[0] == '-' ? -1 : 1);
//     i = (sign > 0 ? 0 : 1);
//     while (ft_ishex(str[i]))
//     {
//         n = n * 10 + ft_baseten(str[i]);
//         i++;
//     }
//     return (n * sign);
// }

// #include <stdio.h>
// int main()
// {
//     char *str = "12fdb3";
//     int res = ft_atoi_base(str, 10);
//     printf("%d\n", res);

//     return 0;
// }