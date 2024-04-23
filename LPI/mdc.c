#include <stdio.h>

int main()
{
    int a, b, lowestvalue;
    scanf("%d %d", &a, &b);
    lowestvalue = a > b ? b : a;
    int i = lowestvalue;
    while (i >= 1)
    {
        if (a % i == 0 && b % i == 0)
            break;
        i--;
    }
    printf("%d\n", i);
}