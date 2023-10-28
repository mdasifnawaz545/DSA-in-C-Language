#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(int data, struct node **top);
void pop(struct node **top, struct node **top1);
void display(struct node **top);
struct node *top = NULL;
struct node *top1 = NULL;
struct node *top2 = NULL;
int main()
{
    push(1, &top);
    push(2, &top);
    push(3, &top);
    display(&top);
    printf("\n");
    pop(&top, &top1);
    printf("\n");
    pop(&top1,&top2);
    printf("\n");
    return 0;
}
void push(int data, struct node **top)
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Stack Overflowed\n.");
        exit(1);
    }

    temp->data = data;
    temp->next = (*top);
    (*top) = temp;
}
void display(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflowed.\n");
        exit(1);
    }
    struct node *ptr = *top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void pop(struct node **top, struct node **top1)
{
    struct node *ptr = *top;
    while (ptr!=NULL)
    {
    push(ptr->data, &top1);
    *top=ptr->next;
    free(ptr);
    ptr=*top;
    }
    display(&top1);

}