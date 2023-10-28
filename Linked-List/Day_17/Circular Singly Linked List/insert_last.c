#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node * addEmpty(int data);
struct node * addEnd(struct node *tail,int data);
int main()
{
    struct node *tail;
    tail=addEmpty(786);
    tail=addEnd(tail,10);
    tail=addEnd(tail,20);
    tail=addEnd(tail,30);
    tail=addEnd(tail,40);
    struct node *p=tail->next;
    int count=0;
    do
    {
        count++;
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);
    printf("\n%d",count);
    return 0;
}
struct node * addEmpty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node * addEnd(struct node *tail,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    return temp;
}