#include <stdio.h>
#include <stdlib.h>
int *read_array(int *array_size)
{
    puts("Enter array size:");
    scanf("%d", array_size);

    int *user_array = (int *)malloc(sizeof(int) * *array_size);

    if (user_array == NULL)
    {
        puts("Could not allocate");
        exit(1);
    }
    short j = 0;
    while (j < *array_size)
    {
        printf("Enter number at index %d:\n", j);
        scanf("%d", user_array + j);
        j++;
    }
    return user_array;
}