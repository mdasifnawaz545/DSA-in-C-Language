#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addBeg(struct node *head, int data);
struct node *reverse(struct node *head);
struct node *add(struct node *head1, struct node *head2, struct node *head3);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    int n1, n2;
    printf("Enter the 1st Number : ");
    scanf("%d", &n1);
    printf("Enter the 2nd Number : ");
    scanf("%d", &n2);
    while (n1 != 0)
    {
        head1 = addBeg(head1, n1 % 10);
        n1 = n1 / 10;
    }
    while (n2 != 0)
    {
        head2 = addBeg(head2, n2 % 10);
        n2 = n2 / 10;
    }
    head1 = reverse(head1);
    head2 = reverse(head2);
    head3 = add(head1, head2, head3);
    struct node *ptr = head3;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
struct node *addBeg(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *ptr = head;
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;
    while (ptr != NULL)
    {
        ptr2 = ptr->next;
        ptr->next = ptr1;
        ptr1 = ptr;
        ptr = ptr2;
    }
    ptr = ptr1;
    return ptr;
}
struct node *add(struct node *head1, struct node *head2, struct node *head3)
{
    int sum = 0, carry = 0;
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        sum = 0;
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
        head3 = addBeg(head3, sum);
        if (ptr1)
        {
            ptr1 = ptr1->next;
        }
        if (ptr2)
        {
            ptr2 = ptr2->next;
        }
    }
    head3 = addBeg(head3, carry);
    return head3;
}