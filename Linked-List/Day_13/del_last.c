#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void del_last(struct node *head);
int main()
{
     struct node *head = malloc(sizeof(struct node));
    head->data = 786;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    head->link->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link->link->link->link = current;

    del_last(head);
    return 0;
}
void del_last(struct node *head)
{
    struct node *ptr=head;
    while (ptr->link->link!=NULL)
    {
        ptr=ptr->link;
    }
    free(ptr->link);
    ptr->link=NULL;
        struct node*ptr1=head;
    while (ptr1!=NULL)
    {
        printf("%d ",ptr1->data);
        ptr1=ptr1->link;
    }
}