#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *reverse(struct node *head);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=1;
    head->next=NULL;
    struct node *current=malloc(sizeof(struct node));
    current->data=2;
    current->next=NULL;
    head->next=current;
    current=malloc(sizeof(struct node));
    current->data=1;
    current->next=NULL;
    head->next->next=current;
    int count=0,test=0;
    struct node *ptr=head;
    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    struct node *head2=NULL;
    head2=reverse(head);
    while (head!=NULL || head2!=NULL)
    {
        if(head->data==head2->data)
        test++;
    }
    if(count==test)
    {
        printf("Palindrome");
    }
    else         printf("Not a Palindrome");
;
    return 0;
}
struct node *reverse(struct node *head)
{
    struct node *temp1=NULL;
    struct node *temp2=head->next;
    while (head!=NULL)
    {
        head->next=temp1;
        head=temp2;
        temp2=temp2->next;
    }
    head=temp1;
    return head;
}