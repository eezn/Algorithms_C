#include "compare.h"

void InsertionSort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        for (j = i; (0 < j && more(arr[j - 1], temp)); j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}