/*
** CODEWARS PROJECT, 2022
** odder_than_rest.c
** Author:
** pasdepseudo
*/

#include <sys/types.h>

ssize_t odd_one(const int *arr, int z) // z = taille du tableau
{
    int i = 0; // index
    while (i < z) {
        if (arr[i] % 2) {
            return i;
        }
        i++;
    }
    return -1;
}
