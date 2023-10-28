#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void  delete_last(struct node *head,struct node *current,struct node *current2);

int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    head->link=current;

    struct node *current2=malloc(sizeof(struct node));
    current2->data=30;
    current2->link=NULL;

    head->link->link=current2;

    current=malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;

    head->link->link->link=current;

    delete_last(head,current,current2);
    return 0;
}
void  delete_last(struct node *head,struct node *current,struct node *current2)
{
    struct node *ptr;
    free(current);
    current2->link=NULL;
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

}