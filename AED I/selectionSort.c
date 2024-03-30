#include <stdio.h>
#include <stdlib.h>

int *read_array();

int main()
{
    int *userArray = read_array();
    return 0;
}

int *read_array()
{
    size_t arraySize;
    puts("Enter array size:");
    scanf("%zu", &arraySize);

    int *userArray = (int *)malloc(arraySize * sizeof(int));
    if (userArray == NULL)
    {
        puts("Could not allocate");
        exit(1);
    }
    short j = 0;
    while (j < arraySize)
    {
        scanf("%d", userArray + j);
        j++;
    }

    return userArray;
}