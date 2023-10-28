#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void del_all(struct node *head);
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 786;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 10;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 20;
    current->link = NULL;
    head->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 30;
    current->link = NULL;
    head->link->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 40;
    current->link = NULL;
    head->link->link->link->link = current;

    del_all(head);
    return 0;
}
void del_all(struct node *head)
{
    struct node *temp = head;
    while(temp!=NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    if (temp==NULL || head==NULL)
    {
        printf("The List is empty now.!");
    }
    
}