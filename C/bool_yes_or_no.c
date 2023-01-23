/*
** CODEWARS PROJECT, 2022
** bool_yes_or_no.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>

const char *bool_to_word (bool value)
{
  if (value == false)
    return "No";
  else
  return "Yes";
}
