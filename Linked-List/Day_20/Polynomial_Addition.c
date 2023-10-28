#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *next;
};
struct node *poly(struct node *head);
struct node *sum(struct node *head3, struct node *head2, struct node *head1);
struct node *sort(struct node *head, int ex, int co);
void display(struct node *head);

int main()
{
    struct node *head1 = NULL;
    printf("Enter the First Polynomial\n");
    head1 = poly(head1);
    printf("Enter the 2nd Polynomial\n");
    struct node *head2 = NULL;
    head2 = poly(head2);
    display(head1);
    display(head2);
    struct node *head3 = NULL;
    head3 = sum(head3, head2, head1);
    printf("\nAdded Polynomial is : ");
    display(head3);
    return 0;
}
struct node *poly(struct node *head)
{
    int coeff, expo, n;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Coefficient of term %d : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the Exponent of term %d : ", i + 1);
        scanf("%d", &expo);
        head = sort(head, expo, coeff);
    }
    return head;
}
struct node *sort(struct node *head, int ex, int co)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->coeff = co;
    temp->expo = ex;
    temp->next = NULL;

    if (head == NULL || ex > head->expo)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL && ex < ptr->next->expo)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("There is no polynomial.");
    }
    else
    {
        struct node *ptr = head;
        while (ptr != NULL)
        {
            printf("(%.1fx^%d)", ptr->coeff, ptr->expo);
            ptr = ptr->next;
            if (ptr != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
struct node *sum(struct node *head3, struct node *head2, struct node *head1)
{
    head3 = NULL;
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = sort(head3, ptr1->expo, ptr1->coeff + ptr2->coeff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = sort(head3, ptr1->expo, ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = sort(head3, ptr2->expo, ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = sort(head3, ptr1->expo, ptr1->coeff);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head3 = sort(head3, ptr2->expo, ptr2->coeff);
        ptr2 = ptr2->next;
    }
    printf("\nAdded Polynomial is : ");
    display(head3);
    return head3;
}