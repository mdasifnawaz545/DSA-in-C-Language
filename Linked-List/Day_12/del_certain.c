#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
    struct node * del_certain(struct node *head,int pos);

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
        
    current=malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link->link->link=current;

    int pos=3;
    struct node* ptr;
    ptr=del_certain(head,pos);
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    

    return 0;
}
    struct node * del_certain(struct node *head,int pos)
    {
        struct node*temp=head;
        pos--;
        while (pos!=1)
        {
            temp=temp->link;
            pos--;
        }
        temp->link=temp->link->link;
        temp=head;
        return temp;

    }
