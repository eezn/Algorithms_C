#include <stdlib.h>

// 시간복잡도: O(n), 공간복잡도: O(n)
void MaxMinArr(int arr[], int size)
{
    int *aux = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        aux[i] = arr[i];

    int start = 0;
    int stop = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = aux[stop];
            stop -= 1;
        }
        else
        {
            arr[i] = aux[start];
            start += 1;
        }
    }
}

void ReverseArr(int arr[], int start, int stop)
{
    int tmp;
    while (start < stop)
    {
        tmp = arr[start];
        arr[start++] = arr[stop];
        arr[stop--] = tmp;
    }
}

// 시간복잡도: O(n^2), 공간복잡도: O(1)
void MaxMinArr2(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        ReverseArr(arr, i, size - 1);
}

// test code
#include <stdio.h>
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(int);
    //MaxMinArr(arr, len);
    MaxMinArr2(arr, len);
    printArray(arr, len);
    return (0);
}
