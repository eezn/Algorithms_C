// O(n)
void indexArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int curr = i;
        int value = -1;

        while (arr[curr] != -1 && arr[curr] != curr)
        {
            int temp = arr[curr];
            arr[curr] = value;
            value = curr = temp;
        }
        if (value != -1)
            arr[curr] = value;
    }
}

// O(n)
void indexArray2(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        while (arr[i] != -1 && arr[i] != i)
        {
            int tmp = arr[i];
            arr[i] = arr[tmp];
            arr[tmp] = tmp;
        }
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
    int arr[] = {8, -1, 6, 1, 9, 3, 2, 7, 4, -1};
    int len = sizeof(arr) / sizeof(int);
    indexArray(arr, len);
    // indexArray2(arr, len);
    printArray(arr, len);
    return (0);
}
