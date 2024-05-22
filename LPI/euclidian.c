#include <stdio.h>

int main()
{
    int a, b, tmp, i = 0;
    int quotients[100], dividers[100], remainders[100];
    scanf("%d %d", &a, &b);

    if (b > a)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    dividers[0] = a;
    while (b != 0)
    {
        quotients[i] = a / b;
        dividers[i + 1] = b;
        remainders[i] = a % b;
        tmp = b;
        b = a % b;
        a = tmp;
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d\t", quotients[j]);
    }
    printf("\n");
    for (int j = 0; j <= i; j++)
    {
        printf("%d\t", dividers[j]);
    }
    printf("\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d\t", remainders[j]);
    }
    return 0;
}