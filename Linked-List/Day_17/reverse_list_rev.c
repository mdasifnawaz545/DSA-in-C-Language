#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *add_empty(struct node *head, int data);
struct node *add_end(struct node *head, int data);
struct node *create_list(struct node *head);
struct node *reverse_list(struct node *head);

int main()
{
    struct node *head = NULL;
    struct node *ptr = head;
    head = create_list(head);
    ptr = head;
    printf("Linked-List Before Reverse : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    ptr = reverse_list(head);
    printf("\nLinked-List After Reverse : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
struct node *add_empty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}
struct node *create_list(struct node *head)
{
    int data, nodes;
    printf("Enter the Number of Nodes : ");
    scanf("%d", &nodes);
    if (nodes == 0)
    {
        head = NULL;
    }
    else if (nodes == 1)
    {
        printf("Enter the Data of the Node 1 : ");
        scanf("%d", &data);
        head = add_empty(head, data);
    }
    else
    {
        struct node *ptr = head;
        printf("Enter the Data of the Node 1 : ");
        scanf("%d", &data);
        head = add_empty(head, data);
        ptr = head;
        for (int i = 1; i < nodes; i++)
        {
            printf("Enter the Data of the Node %d : ", i + 1);
            scanf("%d", &data);
            ptr = add_end(head, data);
        }
        ptr = head;
    }

    return head;
}
struct node *add_end(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    temp->prev = head;
    temp->data = data;
    temp->next = NULL;
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
        head->prev = temp2;
        head = temp2;
    }
    head=temp1;
    return head;
}