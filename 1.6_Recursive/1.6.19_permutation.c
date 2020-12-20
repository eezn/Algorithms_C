#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *arr, int i, int j)
{
    int tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void permutation(int *arr, int i, int length)
{
    if (length == i)
    {
        printArray(arr, length);
        return;
    }
    for (int j = i; j < length; j++)
    {
        swap(arr, i, j);
        permutation(arr, i + 1, length);
        swap(arr, i, j);
    }
}

// test code
int main()
{
    int arr[3];
    for (int i = 0; i < 3; i++)
        arr[i] = i;
    permutation(arr, 0, 3);
}