// Stack Implementaion using a linked-List.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;
void push(int data);
void display();
void pop();
void peek();
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    printf("\n");
    peek();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    // printf("\n");
    // display();
    return 0;
}
void push(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nStack Overflowed.");
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}
void display()
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("\nStack underflowed.");
    }

    struct node *temp = top;
    top = temp->link;
    free(temp);
    temp = NULL;
}
void peek()
{
    struct node *temp=top;
    while (temp->link!=NULL)
    {
        temp=temp->link;
    }
    printf("%d",temp->data);
    
}