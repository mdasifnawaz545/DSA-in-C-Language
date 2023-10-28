#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node * add_to_empty(struct node *head);
int main()
{
    struct  node *head=NULL;
    head=add_to_empty(head);
    printf("%d ",head->data);
    return 0;
}
struct node * add_to_empty(struct node *head)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=786;
    temp->next=NULL;
    head=temp;
    return head;
}