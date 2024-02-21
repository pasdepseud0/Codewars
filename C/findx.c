/*
** CODEWARS PROJECT, 2024
** find_x.c
** Author:
** pasdepseudo
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long int find_x(unsigned long long int number)
{
    unsigned long long int sum_of_i = (unsigned long long int)number * (number - 1) * number; // sum of i

    unsigned long long int sum_of_j = (unsigned long long int)number * (2 * number - 1) * number; // sum of j

    return sum_of_i + sum_of_j; // res of two summ
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 0;
    }

    unsigned long long int n = strtoull(argv[1], NULL, 10);
    unsigned long long int result = find_x(n);
    printf("Result: %llu\n", result);

    return 1;
}