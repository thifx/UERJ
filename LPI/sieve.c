#include <stdio.h>
#include <math.h>
#define SIZE 100
int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = i + 1;
    }

    int limit = sqrt(SIZE);
    for (int i = 1; arr[i] <= limit; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = i + 1; j < SIZE; j++)
            {
                if (arr[j] % arr[i] == 0 && arr[j] != 0)
                {
                    arr[j] = 0;
                }
            }
        }
    }

    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] != 0)
            printf("%d\n", arr[i]);
    }
    return 0;
}
