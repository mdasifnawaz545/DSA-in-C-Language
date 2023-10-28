#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node * del_last(struct node *head);

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=10;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link->link=current;

    struct node*ptr=head;

    ptr=del_last(head);
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}
struct node * del_last(struct node *head)
{
    struct node *ptr1=head;
    struct node *ptr2=head;
    while (ptr2->link!=NULL)
    {
        ptr1=ptr2;
        ptr2=ptr2->link;
    }
    ptr1->link=NULL;
    free(ptr2);
    ptr2=NULL;
    ptr1=head;
    return head;
    


}