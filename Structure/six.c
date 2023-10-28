// Passing array of structure as argument.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    char name[20];
    int id;
};
struct node display(struct node [],int);
int main()
{
    int n;
    printf("Enter the number of details thing you want to store : ");
    scanf("%d",&n);
    struct node info[n];
    struct node detail;
    detail=display(info,n);
    printf("%s  %d",detail.name,detail.id);
    return 0;
}
struct node display(struct node inf[],int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter the name : ");
        gets(inf[i].name);
        printf("Enter the ID : ");
        scanf("%d",&inf[i].id);
    }
    return *inf;
}
