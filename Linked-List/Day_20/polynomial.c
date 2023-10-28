#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *next;
};
struct node *create(struct node *head);
struct node *addSort(struct node *head, int ex, int co);
void display(struct node *head);
void sum(struct node *head1, struct node *head2);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the 1st Polynomial\n");
    head1 = create(head1);
    printf("Enter the 2nd Polynomial\n");
    head2 = create(head2);
    display(head1);
    display(head2);
    sum(head1, head2);
    return 0;
}
void sum(struct node *head1, struct node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        printf("No Polynmial.");
    }
    else
    {
        struct node *ptr1 = head1;
        struct node *ptr2 = head2;
        while (ptr1 != NULL || ptr2 != NULL)
        {

            printf("%.1fX^%d", ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr1 != NULL || ptr2 != NULL)
            {
                printf(" + ");
            }
            else
                printf("\n");
        }
    }
}
struct node *create(struct node *head)
{
    int expo, n;
    int coeff;
    printf("Enter the numbers of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of %d term : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent of %d term : ", i + 1);
        scanf("%d", &expo);
        head = addSort(head, expo, coeff);
    }
    return head;
}
struct node *addSort(struct node *head, int ex, int co)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr;
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
        ptr = head;
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
        printf("There is No Polynomial.");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%.1fX^%d", temp->coeff, temp->expo);
            temp = temp->next;
            if (temp != NULL)
            {
                printf(" + ");
            }
            else
                printf("\n");
        }
    }
}
