#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(int data, struct node **top);
void display(struct node *top);
void reverse(struct node **top);
int pop(struct node **top);
int main()
{
    struct node *top = NULL;
    push(1, &top);
    push(2, &top);
    push(3, &top);
    push(4, &top);
    push(5, &top);
    printf("Original stack is : ");
    display(top);
    reverse(&top);
    printf("\nReverse stack is : ");
    display(top);
    return 0;
}
int pop(struct node **top)
{
    struct node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    temp = NULL;
    return val;
}
void reverse(struct node **top)
{
    struct node *top1 = NULL;
    struct node *top2 = NULL;
    while (*top != NULL)
    {
        push(pop(top), &top1);
    }
    while (top1 != NULL)
    {
        push(pop(&top1), &top2);
    }
    while (top2 != NULL)
    {
        push(pop(&top2), top);
    }
}
void display(struct node *top)
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void push(int data, struct node **top)
{
    struct node *temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->next = *top;
    *top = temp;
}