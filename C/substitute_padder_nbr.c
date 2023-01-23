/*
** CODEWARS PROJECT, 2022
** substitute_padder_nbr.c
** Author:
** pasdepseudo
*/

#include <stdlib.h>

char* solution(int n)
{
  int size = 14;                                    // a size is fixed for a sentence
  char *dest = malloc (sizeof(char) * (size + 1));  // but add + 1 for '\0' and alloc memory for read sentence in order
  char *src = "Value is ";                          // for pass a test add in string this

  dest[size] = '\0';                                // start to '\0' + 1
  while (n != 0) {                                  // while number is different to 0
    dest[size = size - 1] = '0' + (n % 10);         // dest[size] decrement - 1 'cause a str is fixed at 14 and after equal for convert a int to char , if you operate %10 you get a last int
    n = n / 10;                                     // and divided by ten
  }
  while (size-- > 9) {                              // while size is inferior to a digit
    dest[size] = '0';                               // substitute in the char
  }
  for (int i = size; i >= 0; i = i - 1) {           // for incremente a sentence use i for index string
    dest[i] = src[i];                               // the loop increment each char at every turn
  }
  return dest;                                      // return ur result
}
