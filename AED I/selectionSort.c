#include "readarray.h"
#include "printarray.h"

void print_array(int *, int);

int main()
{
    int array_size;
    int *user_array = read_array(&array_size);
    int i = 0;

    while (i < array_size - 1)
    {
        int j = i + 1;
        int min_value = user_array[i];
        while (j < array_size)
        {
            if (user_array[i] > user_array[j])
            {
                min_value = user_array[j];
                user_array[j] = user_array[i];
                break;
            }
            j++;
        }
        user_array[i] = min_value;
        i++;
    }
    print_array(user_array, array_size);
    free(user_array);
    return 0;
}
