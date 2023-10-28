#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int expo;
    struct node *next;
};
struct node *poly(struct node *head);
struct node *add(struct node *head3, struct node *head1, struct node *head2);
struct node *create(struct node *, int ex, int co);
void display(struct node *head);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    printf("Enter the Polyomial 1 : \n");
    head1 = poly(head1);
    display(head1);
    printf("Enter the Polyomial 2 : \n");
    head2 = poly(head2);
    display(head2);

    printf("The added Polynomial is  : \n");
    head3 = add(head3, head1, head2);
    display(head3);
    return 0;
}
struct node *poly(struct node *head)
{
    int coeff;
    int expo;
    int n;
    printf("Enter the  no. of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d : ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent of term %d : ", i + 1);
        scanf("%d", &expo);
        head = create(head, expo, coeff);
    }
    return head;
}
struct node *create(struct node *head, int ex, int co)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = NULL;
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
        // ptr=ptr->next;
    }
    return head;
}
struct node *add(struct node *head3, struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = create(head3, ptr1->expo, ptr1->coeff + ptr2->coeff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = create(head3, ptr1->expo, ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = create(head3, ptr2->expo, ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }

    return head3;
}
void display(struct node *head)
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
        {
            printf("\n");
        }
    }
}