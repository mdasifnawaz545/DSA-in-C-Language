// Creating a node of a circular singly linked list.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
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
    return 0;
}
struct node * add_empty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}