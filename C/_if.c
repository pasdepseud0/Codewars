
/*
** CODEWARS PROJECT, 2023
** _if.c
** Author:
** pasdepseudo
*/

#include <stdbool.h>

void _if(bool value, void (*func1)(), void (*func2)())
{
    if (value)
        func1();
    else
        func2();
}
