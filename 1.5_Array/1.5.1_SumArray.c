int SumArray(int arr[], int size)
{
    int total = 0;
    int index = 0;
    for (index = 0; index < size; index++)
        total = total + arr[index];
    return (total);
}