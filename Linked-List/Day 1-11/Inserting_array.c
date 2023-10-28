#include<stdio.h>
void insert(int a[],int pos,int e);
int main()
{
    int a[5]={1,2,3,4,5};
    printf("The following array is : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    int e,pos;
    printf("\nEnter the element to insert and its position : ");
    scanf("%d %d",&e,&pos);
    insert(a,pos,e);
    return 0;
}
void insert(int a[],int pos,int e)
{

    for (int i = 4; i >= pos-1; i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=e;
    for (int i = 0; i <= 5; i++)
    {
        printf("%d ",a[i]);
    }
    
}