#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node *create(struct node *head);
struct node *poly(struct node *head, int ex, int co);
struct node *add(struct node *head1, struct node *head2, struct node *head3);
struct node *mul(struct node *head1, struct node *head2, struct node *head3);
struct node *add_mul(struct node *head);
void display(struct node *head);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    struct node *head4 = NULL;
    printf("Polynomial 1 : \n");
    head1 = create(head1);
    display(head1);
    head2 = create(head2);
    display(head2);
    printf("Added Polynomial is : ");
    head3 = add(head1, head2, head3);
    display(head3);
    head4 = mul(head1, head2, head4);
    printf("Multliplicated Polynomial is : ");
    head4=add_mul(head4);
    display(head4);
    return 0;
}
struct node *add(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = poly(head3, ptr1->expo, ptr1->coeff + ptr2->coeff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = poly(head3, ptr1->expo, ptr1->coeff);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = poly(head3, ptr2->expo, ptr2->coeff);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = poly(head3, ptr1->expo, ptr1->coeff);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        head3 = poly(head3, ptr2->expo, ptr2->coeff);
        ptr2 = ptr2->next;
    }
    return head3;
}
struct node *add_mul(struct node *head)
{
    struct node *ptr1=head;
    struct node *ptr2=head;
    while (ptr1!=NULL)
    {
        while (ptr2!=NULL)
        {
            if (ptr1->expo==ptr2->expo)
            {
                head=poly(head,ptr1->expo,ptr1->coeff+ptr2->coeff);
            }
            ptr2=ptr2->next;
            
        }
        ptr1=ptr1->next;
        ptr2=head;
        
    }
    while (ptr1!=NULL)
    {
                        head=poly(head,ptr1->expo,ptr1->coeff);
                        ptr1=ptr1->next;

    }
    
 return head;   
}
struct node *mul(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    if (ptr1==NULL || ptr2==NULL)
    {
        printf("Multiplication is zero.");
    }
    
    while (ptr1!=NULL)
    {
        while (ptr2!=NULL)
        {
            head3=poly(head3,ptr1->expo+ptr2->expo,ptr1->coeff*ptr2->coeff);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=head2;
        
    }
    return head3;
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("No Polynomial.");
    }
    else
    {
        struct node *ptr = head;
        while (ptr != NULL)
        {
            printf("%dX^%d", ptr->coeff, ptr->expo);
            ptr = ptr->next;
            if (ptr != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
struct node *create(struct node *head)
{
    int n, coeff, expo;
    printf("Enter the no. of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficent of term %d : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent of term %d : ", i + 1);
        scanf("%d", &expo);
        head = poly(head, expo, coeff);
    }
    return head;
}
struct node *poly(struct node *head, int ex, int co)
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