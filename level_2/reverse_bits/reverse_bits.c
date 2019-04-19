/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
*/

// unsigned char reverse_bits(unsigned char octet)
// {
//   unsigned char r = octet;       // r will be reversed bits of v; first get LSB of v
//   int s = sizeof(octet) * 8 - 1; // extra shift needed at end

//   octet >>= 1;
//   while (octet)
//   {
//     r <<= 1;
//     r |= octet & 1;
//     s--;
//     octet >>= 1;
//   }
//   r <<= s;
//   return (r);
// }

unsigned char reverse_bits(unsigned char octet)
{
  return (
      ((octet & 1) << 7) |
      ((octet >> 1 & 1) << 6) |
      ((octet >> 2 & 1) << 5) |
      ((octet >> 3 & 1) << 4) |
      ((octet >> 4 & 1) << 3) |
      ((octet >> 5 & 1) << 2) |
      ((octet >> 6 & 1) << 1) |
      (octet >> 7 & 1));
}

#include <stdio.h>
int main(void)
{
  for (unsigned char x = 'a'; x <= 'z'; x++)
    printf("%c", (char)reverse_bits(x));
  printf("\n");
  return 0;
}
