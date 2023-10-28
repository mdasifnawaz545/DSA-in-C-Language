#include <stdio.h>
void insert_begin(int arr[], int data, int n);
int main()
{
    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Element : ", i + 1);
        scanf("%d", &arr[i]);
    }

    return 0;
}
void insert_begin(int arr[], int data, int n)
{
    n++;
    for (int i = n; i >= 0; i--)
    {
      
        arr[i] = arr[i - 1];
        
    }
    arr[0] = 786;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}