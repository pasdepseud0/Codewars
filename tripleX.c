/*
** CODEWARS PROJECT, 2022
** tripleX.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>

bool triple_x (const char *string)
{
    int i = 0;
    while (string[i] != 'x' && string[i] != '\0') {
        i++;
    }
    if (string[i] == 'x' && string[i+1] == 'x' && string[i+2] == 'x') {
        return true
            }
    return false;
}
