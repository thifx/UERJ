#include <stdio.h>
#include "util/printarray.h"
int main()
{
    int array1[] = {1, 4, 7, 10, 13};
    int array2[] = {2, 4, 8, 11, 15, 20, 25, 32};
    int sizeofarray1 = (sizeof array1) / __SIZEOF_INT__;
    int sizeofarray2 = (sizeof array2) / __SIZEOF_INT__;
    int arrayslen = sizeofarray1 + sizeofarray2;
    int result[arrayslen];

    int i = 0;
    int j = 0;
    while (i < sizeofarray1 && j < sizeofarray2)
    {
        printf("%d: %d\n", array1[i], array2[j]);
        if (array1[i] <= array2[j])
        {
            result[i + j] = array1[i];
            i++;
        }
        else
        {
            result[i + j] = array2[j];
            j++;
        }
    }
    while (i < sizeofarray1)
    {
        result[i + j] = array1[i];
        i++;
    }
    while (j < sizeofarray2)
    {
        result[i + j] = array2[j];
        j++;
    }
    print_array(result, arrayslen);
    return 0;
}