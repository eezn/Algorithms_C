void swap(int arr[], int idx, int jdx)
{
    int tmp;

    tmp = arr[idx];
    arr[idx] = arr[jdx];
    arr[jdx] = tmp;
}

// O(n^2)
void BubbleSort(int arr[], int size)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = 1;
        while (j < size)
        {
            if (arr[j - 1] > arr[j])
                swap(arr, j - 1, j);
            j++;
        }
        i++;
    }
}

// O(n)
void WaveArray2(int arr[], int size)
{
    for (int i = 1; i < size; i += 2)
    {
        if (0 <= (i - 1) && arr[i - 1] < arr[i])
            swap(arr, i, i - 1);
        if ((i + 1) < size && arr[i] > arr[i + 1])
            swap(arr, i, i + 1);
    }
}

// O(n^2) -> 정렬의 시간복잡도에 따라 달라짐
void WaveArray(int arr[], int size)
{
    BubbleSort(arr, size); // O(n)
    // quickSort(arr, size); // O(nlogn)
    for (int i = 0; i < size - 1; i += 2)
        swap(arr, i, i + 1);
}

// test code
#include <stdio.h>
int main()
{
    int arr[] = {1, 9, 0, -2, -8, -7, 66, 10, -11, 6};
    int len = sizeof(arr) / sizeof(int);
    // BubbleSort(arr, len); // O(n^2)
    // WaveArray(arr, len); // O(n^2)
    WaveArray2(arr, len); // O(n)
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return (0);
}