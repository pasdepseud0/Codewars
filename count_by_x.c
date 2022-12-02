/*
** CODEWARS PROJECT, 2022
** count_by_x.c
** Author:
** pasdepseudo
*/

void count_by(unsigned x, unsigned n, unsigned result[n])
{
    int count = 0;
  //int *array = malloc(sizeof(int) * n);

    while (count < n) {
        count++;
        result[count-1] = x * count;
    }
}
