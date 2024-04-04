#include "../readarray.h"
#include "../printarray.h"

int main()
{
    int array_size;
    int *user_array = read_array(&array_size);

    int desired;
    puts("Type the desired number:");
    scanf("%d", &desired);
    int mid = 0;
    int c = 0;
    int f = array_size - 1;
    while (c <= f)
    {
        mid = (c + f) / 2;
        if (user_array[mid] > desired)
        {
            f = mid - 1;
        }
        else if (user_array[mid] < desired)
        {
            c = mid + 1;
        }
        else
        {
            printf("found at index: %d", mid);
            return 0;
        }
        printf("i: %d;c: %d;f: %d\n", mid, c, f);
    }
    return 0;
}
