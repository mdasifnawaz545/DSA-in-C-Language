#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addEmpty(struct node *head, int data);
struct node *addEnd(struct node *head, int data);
int main()
{
    struct node *head = NULL;
    head = addEmpty(head, 786);
    struct node *ptr = head;
    ptr = addEnd(ptr, 10);
    ptr = addEnd(ptr, 20);
    ptr = addEnd(ptr, 30);
    ptr = addEnd(ptr, 40);
    ptr = addEnd(ptr, 50);
    ptr = addEnd(ptr, 60);
    ptr = addEnd(ptr, 70);
    ptr = addEnd(ptr, 80);
    ptr = head;
    while (ptr->next!= NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    return 0;
}
struct node *addEmpty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *addEnd(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    head->next = temp;
    return temp;
}