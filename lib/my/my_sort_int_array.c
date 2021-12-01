/*
** EPITECH PROJECT, 2021
** C Pool Day04
** File description:
** sorts an integer array
*/

static int myswapint(int *a, int *b)
{
    int tmp = 0;

    if (*a > *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
        return (1);
    }
    return (0);
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int swapped = 0;

    while (j != size) {
        while (i < size && swapped != 1) {
            swapped = myswapint(&array[i], &array[i + 1]);
            i++;
        }
        j++;
        i = 0;
        swapped = 0;
    }
}
