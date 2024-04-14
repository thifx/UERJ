#include "../util/printarray.h"
#include "../util/readarray.h"

int main()
{
    int array_size;
    int *user_array = read_array(&array_size);

    int desired;
    puts("Type the desired number:");
    scanf("%d", &desired);
    int mid = 0;
    int lo = 0;
    int hi = array_size - 1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (user_array[mid] > desired)
        {
            hi = mid - 1;
        }
        else if (user_array[mid] < desired)
        {
            lo = mid + 1;
        }
        else
        {
            printf("found at index: %d\n", mid);
            return 0;
        }
    }
    return 0;
}
