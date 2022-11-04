/*
** CODEWARS PROJECT, 2022
** L1_Set_Alarm.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>

bool set_alarm(bool employed, bool vacation) {
  if (employed && !vacation)
    return true;
  return false;
}
