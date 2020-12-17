void reverseArray(int arr[], int n)
{
    int idx, jdx, tmp;

    idx = 0;
    jdx = n - 1;
    while (idx < jdx)
    {
        tmp = arr[idx];
        arr[idx++] = arr[jdx];
        arr[jdx--] = tmp;
    }

    // for (int i = 0, j = n - 1; i < j; i++, j--)
    //     arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
}

void rotateArray(int arr[], int n, int k)
{
    reverseArray(arr, k);
    reverseArray(&arr[k], n - k);
    reverseArray(arr, n);
}