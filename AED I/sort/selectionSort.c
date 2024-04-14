#include "../util/printarray.h"
#include "../util/readarray.h"

int main()
{
    int array_size;
    int *user_array = read_array(&array_size);
    int i = 0;
    int tmp;

    while (i < array_size - 1)
    {
        int j = i + 1;
        int min_value = i;
        while (j < array_size)
        {
            if (user_array[min_value] > user_array[j])
            {
                min_value = j;
            }
            j++;
        }
        tmp = user_array[i];
        user_array[i] = user_array[min_value];
        user_array[min_value] = tmp;
        i++;
    }
    print_array(user_array, array_size);
    free(user_array);
    return 0;
}
