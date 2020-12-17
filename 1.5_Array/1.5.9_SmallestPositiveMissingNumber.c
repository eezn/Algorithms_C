// brute force : O(n^2)
int SmallestPositiveMissingNumber(int arr[], int size)
{
    int found;
    for (int i = 1; i < size + 1; i++)
    {
        found = 0;
        for (int j = 0; j < size; j++)
            if (arr[j] == i)
            {
                found = 1;
                break;
            }
        if (found == 0)
            return (i);
    }
    return (-1);
}

// HashTable : O(n)
int SmallestPositiveMissingNumber2(int arr[], int size)
{
    HashTable hs;
    for (int i = 0; i < size; i++)
        HashAdd(&hs, arr[i]);
    for (int i = 1; i < size + 1; i++)
        if (!HashFind(hs, i))
            return (i);
    return (-1);
}

// Sub Array : O(n)
int SmallestPositiveMissingNumber3(int arr[], int size)
{
    int *aux = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        if (0 < arr[i] && arr[i] <= size)
            aux[arr[i] - 1] = arr[i];
    for (int i = 0; i < size; i++)
        if (aux[i] != i + 1)
            return (i + 1);
    return (-1);
}

// 시간복잡도: O(n), 공간복잡도: O(1)
int SmallestPositiveMissingNumber4(int arr[], int size)
{
    int tmp;
    for (int i = 0; i < size; i++)
        while (arr[i] != i + 1 && 0 < arr[i] && arr[i] <= size)
        {
            tmp = arr[i];
            arr[i] = arr[tmp - 1];
            arr[tmp - 1] = tmp;
        }
    for (int i = 0; i < size; i++)
        if (arr[i] != i + 1)
            return (i + 1);
    return (-1);
}