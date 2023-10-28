#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node * reverse(struct node * head);
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    head->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 50;
    current->link = NULL;
    head->link->link->link->link = current;

    struct node*ptr=head;
    ptr=reverse(head);
    while (ptr!=NULL)
    {
       printf("%d ",ptr->data);
       ptr=ptr->link;
    }
    
    return 0;
}
struct node * reverse(struct node * head)
{
    struct node *prev=NULL;
    struct node *next=NULL;
    while (head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return prev;
}