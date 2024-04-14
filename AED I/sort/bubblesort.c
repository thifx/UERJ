#include "../util/printarray.h"
#include "../util/readarray.h"

int main()
{
    int array_size;
    int *userArray = read_array(&array_size);

    for (int i = array_size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (userArray[j] > userArray[j + 1])
            {
                int tmp = userArray[j + 1];
                userArray[j + 1] = userArray[j];
                userArray[j] = tmp;
            }
        }
    }
    print_array(userArray, array_size);
    return 0;
}