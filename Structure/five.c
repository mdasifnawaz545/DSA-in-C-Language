// Returning a pointer to a structure from the function.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    char name[20];
    int roll;
};
struct node* send(struct node *);
int main()
{
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *new;
    new=send(&n1);
    printf("%s %d",new->name,new->roll);
    return 0;
}
struct node* send(struct node *n)
{
    printf("Enter the name : ");
    gets(n->name);
    printf("Enter the roll number : ");
    scanf("%d",&(n->roll));
    return &n;
}