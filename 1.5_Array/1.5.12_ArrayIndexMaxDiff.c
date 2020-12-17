// brute force: O(n^2), O(1)
int ArrayIndexMaxDiff(int arr[], int size)
{
    int maxDiff = -1;
    int j;
    for (int i = 0; i < size; i++)
    {
        j = size - 1;
        while (j > i)
        {
            maxDiff = max(maxDiff, j - i);
            break;
        }
        j--;
    }
    return (maxDiff);
}

//O(n), O(n)
int ArrayIndexMaxDiff2(int arr[], int size)
{
    int *leftMin = (int *)malloc(sizeof(int) * size);
    int *rightMax = (int *)malloc(sizeof(int) * size);
    leftMin[0] = arr[0];
    int i, j;
    int maxDiff;

    for (i = 1; i < size; i++)
    {
        if (leftMin[i - 1] < arr[i])
            leftMin[i] = leftMin[i - 1];
        else
            leftMin[i] = arr[i];
    }

    rightMax[size - 1] = arr[size - 1];
    for (i = size - 2; i >= 0; i--)
    {
        if (rightMax[i + 1] > arr[i])
            rightMax[i] = rightMax[i + 1];
        else
            rightMax[i] = arr[i];
    }

    i = 0;
    j = 0;
    maxDiff = -1;
    while (j < size && i < size)
    {
        if (leftMin[i] < rightMax[j])
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return (maxDiff);
}