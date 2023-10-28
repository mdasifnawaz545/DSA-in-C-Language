#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node * add_empty(int data);
int main()
{
    struct node *tail;
    tail=add_empty(786);
    printf("%d ",tail->data);
    printf("%d ",tail->next->data);
    printf("%d ",tail->prev->data);
    return 0;
}
struct node * add_empty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}