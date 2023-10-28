#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void push(int data,struct node * *top1);
void display(struct node *top);
int pop(struct node **top);
void reverse_stack(struct node **top);
int main()
{
    struct node *top=NULL;
    push(1,&top);
    push(2,&top);
    push(3,&top);
    display(top);
    reverse_stack(&top);
    printf("\nStack is Reversed\n");
    display(top);
    return 0;
}
void push(int data,struct node **top1)
{
    struct node *temp=malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        temp->data=data;
        temp->next=*top1;
        *top1=temp;
    }
    
}
void display(struct node *top)
{
    struct node *ptr=top;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}
void reverse_stack(struct node **top)
{
    struct node *top1=NULL;
    struct node *top2=NULL;
    while (*top!=NULL)
    {
        push(pop(&top),&top1);
    }
    while (top1!=NULL)
    {
        push(pop(&top1),&top2);
    }
    while (top2!=NULL)
    {
        push(pop(&top2),&top);
    }
    
    
}
int pop(struct node **top)
{
    int val;
    struct node *temp=*top;
    val=temp->data;
    *top=temp->next;
    free(temp);
    temp=NULL;
    return val;
}