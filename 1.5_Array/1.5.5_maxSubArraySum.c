int maxSubArraySum(int arr[], int size)
{
    int maxSoFar = 0;
    int maxEndingHere = 0;
    int i = 0;
    while (i < size)
    {
        maxEndingHere = maxEndingHere + arr[i++];
        if (maxEndingHere < 0)
            maxEndingHere = 0;
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }
    return (maxSoFar);
}

// test code
#include <stdio.h>
int main()
{
    int arr[] = {-7, 6, -8, -4, 3, -8, 2, 1, -1, -3, -5, -9, 8, 0};
    int len = sizeof(arr) / sizeof(int);
    printf("%d", maxSubArraySum(arr, len));
}