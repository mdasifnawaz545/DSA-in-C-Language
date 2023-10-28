#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addEmpty(struct node *tail);
int searching(struct node *tail);
struct node *addEnd(struct node *tail, int data);
int main()
{
    struct node *tail = NULL;
    tail = addEmpty(tail);
    tail = addEnd(tail, 10);
    tail = addEnd(tail, 20);
    tail = addEnd(tail, 30);
    tail = addEnd(tail, 40);
    struct node *ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    int search;
    search=searching(tail);
    printf("The Position of element is %d\n",search);
    return 0;
}
struct node *addEmpty(struct node *tail)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = 786;
    temp->next = temp;
    tail = temp;

    return tail;
}
struct node *addEnd(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;

    return tail;
}
int searching(struct node *tail)
{
    int element;
    printf("Enter the element : ");
    scanf("%d",&element);
    int index=1;
    struct node *ptr=tail->next;
    if (tail==NULL)
    {
        return -2;
    }
    {
        /* code */
    }
    
    do
    {
        if (ptr->data==element)
        {
          return index;
        }
        index++;
        ptr=ptr->next;
    } while (ptr!=tail->next);
    return -1;
}