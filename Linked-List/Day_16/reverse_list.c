// Creating a doubly linked list by using user defined function and with the user inputs.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *create_list(struct node *head);
struct node *add_empty(struct node *head, int data);
struct node *add_last(struct node *head, int data);
struct node *reverse_list(struct node *head);

int main()
{
    struct node *head = NULL;
    head = create_list(head);
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    ptr = reverse_list(head);
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
struct node *create_list(struct node *head)
{
    struct node *ptr = head;
    int n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    if (n == 0)
    {
        return head;
    }
    else if (n == 1)
    {
        printf("Enter the data of 1 node : ");
        scanf("%d", &data);
        head = add_empty(head, data);
        return head;
    }
    else
    {
        struct node *temp;
        printf("Enter the data of 1 node : ");
        scanf("%d", &data);
        head = add_empty(head, data);
        for (int i = 1; i < n; i++)
        {
            printf("Enter the data of %d value : ", i + 1);
            scanf("%d", &data);
            temp = add_last(head, data);
        }
        temp = head;
    }
    return head;
}
struct node *add_empty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return temp;
}
struct node *add_last(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return temp;
}
struct node *reverse_list(struct node *head)
{
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;
    while (head!= NULL)
    {
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        temp1->prev=temp2;
        head = temp2;
    }
    head = temp1;
    return head;
}