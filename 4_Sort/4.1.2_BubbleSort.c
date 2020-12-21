#include "compare.h"

// 일반적인 버블 정렬
void BubbleSort(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < (size - 1); i++)
        for (j = 0; j < (size - 1 - i); j++)
            if (more(arr[j], arr[j + 1]))
                swap(arr, j, j + 1);
}

// 외부 반복문의 한 패스에서 더 이상 교환할 것이 없으면 배열은 이미 정렬된 상태이므로 정렬을 멈춤.
void BubbleSort2(int arr[], int size)
{
    int i, j, temp, swapped = 1;
    for (i = 0; (size - 1) && swapped; i++)
    {
        swapped = 0;
        for (j = 0; j < (size - 1 - i); j++)
            if (more(arr[j], arr[j + 1]))
            {
                swap(arr, j, j + 1);
                swapped = 1;
            }
    }
}

// test code
int main()
{
    int arr[10] = {4, 5, 3, 2, 6, 7, 1, 8, 9, 10};
    int len = sizeof(arr) / sizeof(int);
    printArray(arr, len);
    BubbleSort2(arr, len);
    printArray(arr, len);
}