#include <stdio.h>
void print_array(int *array, int array_size)
{
    int i = 0;
    while (i < array_size)
    {
        printf("item[%d]: %d\n", i, array[i]);
        i++;
    }
}