int maxPathSum(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0;
    int result = 0;
    int sum1 = 0, sum2 = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            sum1 += arr1[i++];
        else if (arr1[i] > arr2[j])
            sum2 += arr2[j++];
        else
        {
            result += max(sum1, sum2);
            result += arr1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }
    while (i < size1)
        sum1 += arr1[i++];
    while (j < size2)
        sum2 += arr2[j++];
    result += max(sum1, sum2);
    return (result);
}

// test code
#include <stdio.h>
int main()
{
    int arr1[] = {12, 13, 18, 20, 22, 26, 70};
    int arr2[] = {11, 15, 18, 19, 20, 26, 30, 31};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    printf("최대 경로 합: %d\n", maxPathSum(arr1, len1, arr2, len2));
}