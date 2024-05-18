#include <stdio.h>
int main()
{
    int size;
    scanf("%d", &size);

    int v1[size], v2[size];

    for (int i = 0; i < size * 2; i++)
    {
        if (i < size)
            scanf("%d", &v1[i]);
        else
            scanf("%d", &v2[i - size]);
    }

    int scalar_product = 0;
    for (int i = 0; i < size; i++)
    {
        scalar_product += v1[i] * v2[i];
    }

    printf("%d", scalar_product);
    return 0;
}