#include<stdio.h>
void add(int a[],int e, int n);
int main()
{
    int a[10];
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d Element : \n",i+1);
        scanf("%d",&a[i]);
    }
    printf("Array is : ");
    for (int i = 0; i < n; i++)
    {
       printf("%d ",a[i]);
    }
    int e;
    printf("Enter the element you want to add : ");
    scanf("%d",&e);
    add(a,e,n);


    return 0;


}
void add(int a[],int e, int n)
{
a[n]=e;
    printf("Array After is : ");
    for (int i = 0; i <= n; i++)
    {
       printf("%d ",a[i]);
    }
}