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
struct node *create(struct node *head, int co, int ex);
struct node *mul(struct node *head3, struct node *head2, struct node *head1);
void display(struct node *head);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    printf("Enter the 1st Polynomial\n");
    head1 = poly(head1);
    display(head1);
    printf("Enter the 2nd Polynomial\n");
    head2 = poly(head2);
    display(head2);
    head3 = mul(head3, head2, head1);
    display(head3);
    return 0;
}
struct node *poly(struct node *head)
{
    int n, expo, coeff;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the Exponent of term %d : ", i + 1);
        scanf("%d", &expo);
        head = create(head, coeff, expo);
    }
    return head;
}
void display(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("No Polynomial.");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%.1fX^%d", ptr->coeff, ptr->expo);
            ptr = ptr->next;
            if (ptr != NULL)
            {
                printf(" + ");
            }
            else
                printf("\n");
        }
    }
}
struct node *create(struct node *head, int co, int ex)
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
        while ((ptr->next != NULL && ptr->next->expo > ex))
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}
struct node *mul(struct node *head3, struct node *head2, struct node *head1)
{
    struct node *p1 = head1;
    struct node *p2 = head2;
    struct node *p3 = head3;
    if (p1 == NULL || p2 == NULL)
    {
        return 0;
    }
    else
    {
        while (p1!= NULL)
        {
            while (p2!= NULL)
            {
                head3 = create(head3, p1->coeff * p2->coeff, p1->expo + p2->expo);
                p2 = p2->next;
            }
            p2=head2;
            p1 = p1->next;
        }
    }
    return head3;
}