#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add(struct node *head,int data);
int main()
{
    struct node *head=NULL;
    head=add(head,786);
    printf("%d ",head->data);
    return 0;
}
struct node *add(struct node *head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}