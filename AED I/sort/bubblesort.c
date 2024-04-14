#include "../util/printarray.h"
#include "../util/readarray.h"

int main()
{
    int array_size;
    int *userArray = read_array(&array_size);

    print_array(userArray, array_size);
    return 0;
}