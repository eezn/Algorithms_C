// O(n)
void Sort1toN(int arr[], int size)
{
    int curr, value, next;
    for (int i = 0; i < size; i++)
    {
        curr = i;
        value = -1;
        while (0 <= curr && curr < size && arr[curr] != curr + 1)
        {
            next = arr[curr];
            arr[curr] = value;
            value = next;
            curr = next - 1;
        }
    }
}

// O(n)
void Sort1toN2(int arr[], int size)
{
    int tmp;
    for (int i = 0; i < size; i++)
        while (arr[i] != i + 1 && arr[i] > 1)
        {
            tmp = arr[i];
            arr[i] = arr[tmp - 1];
            arr[tmp - 1] = tmp;
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
    int arr[] = {4, 8, 1, 7, 9, 2, 6, 3, 5};
    int len = sizeof(arr) / sizeof(int);
    Sort1toN(arr, len);
    // Sort1toN2(arr, len);
    printArray(arr, len);
    return (0);
}
