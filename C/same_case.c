/*
** CODEWARS PROJECT, 2023
** same_case.c
** Author:
** pasdepseudo
*/

#include <ctype.h>

int same_case(const char a, const char b)
{
    if (!isalpha(a) || !isalpha(b)) {
        return -1;
    }
    if (isupper(a) == isupper(b)) {
        return 1;
    }
    return 0;
}
