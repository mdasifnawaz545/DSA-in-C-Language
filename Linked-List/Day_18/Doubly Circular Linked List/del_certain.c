#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *addEmpty(int data);
struct node *addBegin(struct node *tail, int data);
struct node *addLast(struct node *tail, int data);
struct node *addCertain(struct node *tail, int pos, int data);
struct node *delCertain(struct node *tail, int pos);
struct node *sorting(struct node *tail);
int main()
{
    struct node *tail;
    tail = addEmpty(20);
    tail = addBegin(tail, 10);
    tail = addLast(tail, 30);
    tail = addLast(tail, 40);
    tail = addLast(tail, 50);
    tail = addLast(tail, 60);
    tail = addLast(tail, 70);
    tail = addCertain(tail, 6, 60);
    tail = delCertain(tail, 5);
    tail = sorting(tail);
    struct node *p = tail->next;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);

    return 0;
}
struct node *addEmpty(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = temp;
    temp->next = temp;
    return temp;
}
struct node *addBegin(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = tail->next;
    temp->prev = tail;
    tail->next->prev = temp;
    tail->next = temp;
    return tail;
}
struct node *addLast(struct node *tail, int data)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = tail->next;
    ptr->prev = tail;
    tail->next->prev = ptr;
    tail->next = ptr;
    tail = tail->next;
    return tail;
}
struct node *addCertain(struct node *tail, int pos, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *p = tail->next;
    temp->data = data;
    pos--;
    while (pos != 1)
    {
        p = p->next;
        pos--;
    }
    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;
    return tail;
}
struct node *delCertain(struct node *tail, int pos)
{
    struct node *p = tail->next;
    pos--;
    while (pos != 1)
    {
        p = p->next;
        pos--;
    }
    struct node *p1 = p->next;
    p->next = p1->next;
    p1->next->prev = p;
    free(p1);
    p1 = NULL;
    return tail;
}
struct node *sorting(struct node *tail)
{
    struct node *p = tail->next;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != tail->next);
    p = tail->next;
    struct node *ptr=tail->next;
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < count; i++)
        {
            if (ptr->data < p->next->data)
            {
                p = p->next;
            }
            else 
            {
                int temp=ptr->data;
                ptr->data=p->next->data;
                p->next->data=temp;
                p=p->next;
            }
        }
        ptr=ptr->next;
    }
    tail=ptr;
    return tail;
}