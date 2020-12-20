int BinarySearchRecursive(int arr[], int low, int high, int value)
{
    if (low > high)
        return (-1);
    int mid = (low + high) / 2;
    if (arr[mid] == value)
        return (mid);
    else if (arr[mid] < value)
        return (BinarySearchRecursive(arr, mid + 1, high, value));
    else
        return (BinarySearchRecursive(arr, low, mid - 1, value));
}

// test code
#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(int);
    printf(" %d ", BinarySearchRecursive(arr, 0, len - 1, 6));
    printf(" %d ", BinarySearchRecursive(arr, 0, len - 1, 16));
    return (0);
}