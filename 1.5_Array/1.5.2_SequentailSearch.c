int SequentialSearch(int arr[], int size, int value)
{
    int i = 0;
    for (i = 0; i < size; i++)
        if (value == arr[i])
            return (i);
    return (-1);
}