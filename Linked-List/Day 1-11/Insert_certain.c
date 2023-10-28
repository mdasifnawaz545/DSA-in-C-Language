// The time complexity of this code in O(1).
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void add_pos(struct node* head,int pos,int data);
int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node* current=malloc(sizeof(struct node));
    current->data=788;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=789;
    current->link=NULL;
    head->link->link=current;

    int pos=3,data=787;
    add_pos(head,pos,data);

    return 0;
}
void add_pos(struct node* head,int pos,int data)
{
    struct node* ptr, *temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr=head;
    int count=0;
    temp->link=ptr->link;
    ptr->link=temp;
    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        count++;
        ptr=ptr->link;
    }
    
    printf("No. of nodes : %d",count);
}