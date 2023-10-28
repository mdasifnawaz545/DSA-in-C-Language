#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node* del_first(struct node *head);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=786;
    current->link=NULL;
    head->link=current;
    struct node *ptr;
    ptr=del_first(head);
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}
struct node* del_first(struct node *head)
{
    struct node *temp=head;
    head=head->link;
    free(temp);
    temp=NULL;

    return head;
}