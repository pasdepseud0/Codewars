/*
** CODEWARS PROJECT, 2022
** string_repeat.c
** Author:
** pasdepseudo
*/


#include <string.h>
#include <stdlib.h>

char *repeat_str(int count, const char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (count * strlen(src)+ 1));
    for(int a = 0;a < count;a++) {
        for(int b = 0;src[b] != '\0';b++) {
            dest[i] = src[b];
            i++;
        }
    }
    dest[i] = '\0';
    return dest;
}
