#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void add_certain(struct node *current,struct node *current2 ,struct node *head ,int data);
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=787;
    current->link=NULL;

    head->link=current;

    struct node *current2=malloc(sizeof(struct node));
    current2->data=989;
    current2->link=NULL;

    head->link->link=current;
    int data=1000;
    add_certain(current,current2,head,data);

    return 0;
}
void add_certain(struct node *current,struct node *current2 ,struct node *head ,int data)
{
    struct node *pt=head;
    struct node* ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=current;
    pt->link=ptr;
    pt=head;
    while (pt!=NULL)
    {
        printf("%d ",pt->data);
        pt=pt->link;
    }
    

}