#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int **ptr,*ptr1,n;
    printf("Enter no of rows");
    scanf("%d",&n);
    ptr=(int**)malloc(n*sizeof(int*));
    printf("Enter no of columns");
    int m;
    scanf("%d",&m);
    printf("Input the array");
    for(int i=0;i<n;i++)
    {
        ptr1=(int*)malloc(m*sizeof(int));
        for(int j=0;j<m;j++)
        {
            scanf("%d",ptr1+j);
        }
    }
    printf("The Entered Array:\n");
    for(int i=0;i<n;i++)
    {
        ptr1=*(ptr+i);
        for(int j=0;i<m;j++)
        {
            printf("%",)
        }
    }

    return 0;
}