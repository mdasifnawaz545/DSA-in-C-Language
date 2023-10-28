#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addLinkedList(struct node *head3, struct node *head2, struct node *head1);
struct node *addEnd(struct node *head, int data);
struct node *reverse(struct node *head);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    int n1, n2;
    printf("Enter number 1 : ");
    scanf("%d", &n1);
    printf("Enter number 2 : ");
    scanf("%d", &n2);
    while (n1 != 0)
    {
        head1 = addEnd(head1, n1 % 10);
        n1 = n1 / 10;
    }
    while (n2 != 0)
    {
        head2 = addEnd(head2, n2 % 10);
        n2 = n2 / 10;
    }
    addLinkedList(head3, head2, head1);
    printf("\n");
    head1 = reverse(head1);
    head2 = reverse(head2);
    struct node *ptr1 = head1;
    while (ptr1 != NULL)
    {
        printf("%d ", ptr1->data);
        ptr1 = ptr1->next;
    }
    struct node *ptr2 = head2;
    printf("\n");
    while (ptr2 != NULL)
    {
        printf("%d ", ptr2->data);
        ptr2 = ptr2->next;
    }
    return 0;
}
struct node *addEnd(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}
void addLinkedList(struct node *head3, struct node *head2, struct node *head1)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    int sum = 0, carry = 0;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        sum=0;
        if (ptr1 != NULL)
        {
            sum = sum + ptr1->data;
        }
        if (ptr2 != NULL)
        {
            sum = sum + ptr2->data;
        }
        sum = sum + carry;
        carry = sum / 10;
        sum = sum % 10;
        head3 = addEnd(head3, sum);
        if (ptr1 != NULL)
        {
            ptr1 = ptr1->next;
        }
        if (ptr2 != NULL)
        {
            ptr2 = ptr2->next;
        }
    }
    if (carry != 0)
    {
        head3 = addEnd(head3, carry);
    }
    head3 = reverse(head3);
    struct node *ptr3 = head3;
    printf("\n");
    while (ptr3 != NULL)
    {
        printf("%d ", ptr3->data);
        ptr3 = ptr3->next;
    }
}
struct node *reverse(struct node *head)
{
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;
    while (head != NULL)
    {
        ptr2 = head->next;
        head->next = ptr1;
        ptr1 = head;
        head = ptr2;
    }
    head = ptr1;
    return head;
}