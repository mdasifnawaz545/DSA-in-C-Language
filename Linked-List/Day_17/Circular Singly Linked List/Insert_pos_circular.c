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
int main()
{
    struct node *tail;
    tail = addEmpty(10);
    tail = addBegin(tail, 786);
    tail = addEnd(tail, 20);
    tail = addEnd(tail, 40);
    tail = addEnd(tail, 50);
    tail = addCertain(tail, 30);
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
    temp->next = temp;
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
    struct node *p = tail->next;
    int pos;
    printf("Enter the Position : ");
    scanf("%d", &pos);
    pos--;
    while (pos != 1)
    {
        p = p->next;
        pos--;
    }
    temp->next = p->next;
    p->next = temp;
    return tail;
}