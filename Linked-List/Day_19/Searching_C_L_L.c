// Creatig a Singly circular linked list.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addEmpty(int data);
struct node *addBegin(struct node *tail, int data);
struct node *addEnd(struct node *tail, int data);
struct node *addCertain(struct node *tail, int data);
int searching(struct node *tail);
int main()
{
    struct node *tail;
    tail = addEmpty(10);
    tail = addBegin(tail, 786);
    tail = addEnd(tail, 20);
    tail = addEnd(tail, 30);
    tail = addEnd(tail, 50);
    tail = addEnd(tail, 60);
    tail = addCertain(tail, 40);
    int search;
    search = searching(tail);
    struct node *p = tail->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    if (search==-2)
    {
    printf("The List is Empty.");
    }
    else if (search==-1)
    {
           printf("There is no element in the Liked List.");

    }
    
        else    printf("The Position of the element in the Liked List is : %d",search);
    return 0;
}
struct node *addEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct node *addBegin(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
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
struct node *addCertain(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    int pos = 5;
    struct node *p = tail->next;
    pos--;
    while (pos != 1)
    {
        p = p->next;
        pos--;
    }
    temp->next = p->next;
    p->next = temp;
    if (p == tail)
    {
        tail = tail->next;
    }
    return tail;
}
int searching(struct node *tail)
{
    struct node *temp = tail->next;
    int index = 0, data;
    printf("Enter the data : ");
    scanf("%d", &data);
    if (tail == NULL)
    {
        return -2;
    }
    else
    {

        do
        {
            if (temp->data != data)
            {
                return index;
            }
            index++;
            temp = temp->next;
        } while (temp != tail->next);
    }
    return -1;
}
