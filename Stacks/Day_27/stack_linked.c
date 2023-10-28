#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int data);
void display();
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    return 0;
}
void push(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
}
void display()
{
    struct node *ptr=top;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}