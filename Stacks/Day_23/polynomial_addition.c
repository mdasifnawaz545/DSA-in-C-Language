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
struct node *poly(struct node *head, int ex, int co);
void display(struct node *head);
struct node *polyAdd(struct node *head3, struct node *head2, struct node *head1); 
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    printf("Enter the First Polynomial\n");
    head1 = create(head1);
    display(head1);
    printf("Enter the First Polynomial\n");
    head2 = create(head2);
    display(head2);
    head3 = polyAdd(head3, head2, head1);
    printf("Added Polynomial is : ");
    display(head3);
    return 0;
}
struct node *polyAdd(struct node *head3, struct node *head2, struct node *head1) 
{
    struct node *ptr=head3;
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1->expo==ptr2->expo)
        {
            head3=poly(head3,ptr1->expo,ptr1->coeff+ptr2->coeff);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3=poly(head3,ptr1->expo,ptr1->coeff);
            ptr1=ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3=poly(head3,ptr2->expo,ptr2->coeff);
            ptr2=ptr2->next;
        }
        
        
        
    }
    while (ptr1!=NULL)
    {
        head3=poly(head3,ptr1->expo,ptr1->coeff);
        ptr1=ptr1->next;
    }
    while (ptr2!=NULL)
    {
        head3=poly(head3,ptr2->expo,ptr2->coeff);
        ptr2=ptr2->next;
    }
    return head3;
    
}
struct node *create(struct node *head)
{
    int n, expo, coeff;
    printf("Enter the numbers of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the Exponent of term %d : ", i + 1);
        scanf("%d", &expo);
        head = poly(head, expo, coeff);
    }
    return head;
}
struct node *poly(struct node *head, int ex, int co)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->expo = ex;
    temp->coeff = co;
    temp->next = NULL;
    if (head == NULL || head->expo < ex)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL && ptr->next->expo > ex)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        return head;
    }
}
void display(struct node *head)
{
    struct node *ptr = head;
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
