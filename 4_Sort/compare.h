#ifndef __COMPARE_H__
#define __COMPARE_H__

#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int arr[], int i, int j)
{
    int tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int arrlen(int arr[])
{
    return (sizeof(arr) / sizeof(int));
}

int less(int value1, int value2)
{
    return (value1 < value2);
}

int more(int value1, int value2)
{
    return (value1 > value2);
}

#endif