#include <stdio.h>
void QuickSort(int arr[], int lb, int ub);
void Merge(int arr[], int lb, int mid, int ub);
int main()
{
    int arr[] = {15, 5, 24, 8, 1, 2, 16, 10, 20};
    int lb = 0;
    int ub = sizeof(arr) / sizeof(int);
    printf("Original Array is : ");
    for (int i = lb; i < ub; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    QuickSort(arr, lb, ub);
    return 0;
}
void QuickSort(int arr[], int lb, int ub)
{
    int mid = (lb + ub) / 2;
    if (lb < ub)
    {
        QuickSort(arr, lb, mid);
        QuickSort(arr, mid + 1, ub);
        Merge(arr, lb, mid, ub);
    }
}
void Merge(int arr[], int lb, int mid, int ub)
{
    int i, j, k;
    int b[10];
    i = lb;
    j = mid + 1;
    k = ub;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (j > ub)
    {

        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    else
    {

        while (j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    // for (int c = lb; c < ub; c++)
    // {
    //     arr[c] = b[c];
    // }
    printf("\n");
    printf("Sorted Array is : ");
    for (int i = lb; i < ub; i++)
    {
        printf("%d ", b[i]);
    }
}