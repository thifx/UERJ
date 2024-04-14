#include "../util/printarray.h"
#include "../util/readarray.h"

int main()
{
    int array_size;
    int *userArray = read_array(&array_size);

    for (int i = 1; i < array_size; i++)
    {
        int key = userArray[i];
        int j = i - 1;
        while (j >= 0 && key < userArray[j])
        {
            userArray[j + 1] = userArray[j];
            j--;
        }
        userArray[j + 1] = key;
    }
    print_array(userArray, array_size);
    return 0;
}