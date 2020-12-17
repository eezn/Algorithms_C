// 정렬된 배열에서
int BinarySearch(int arr[], int size, int value)
{
    int low, mid, high;

    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);
        if (arr[mid] == value)
            return (mid);
        else if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (-1);
}