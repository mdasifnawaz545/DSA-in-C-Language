#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void del_c(struct node *head,int pos);
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

    int pos = 3;
    del_c(head, pos);

    return 0;
}
void del_c(struct node *head,int pos)
{
    struct node *ptr1=head;
    struct node *ptr2=head;

    while (pos!=1)
    {
        ptr2=ptr1;
        ptr1=ptr1->link;
        pos--;
    }
    ptr2->link=ptr1->link;
    free(ptr1);
    ptr1=NULL;

    struct node*ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
}