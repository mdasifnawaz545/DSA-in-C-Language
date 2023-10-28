// Write a program to add two polynomial.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node *create(struct node *poly1);
void display(struct node *poly1);
struct node *poly(struct node *poly1, int co, int ex);
struct node *add(struct node *addPoly, struct node *poly1, struct node *poly2);
int main()
{
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *addPoly = NULL;
    printf("Enter Polynomial 1 :");
    printf("\n");
    poly1 = create(poly1);
    display(poly1);
    printf("Enter Polynomial 2 :");
    poly2 = create(poly2);
    printf("\n");
    display(poly2);
    addPoly = add(addPoly, poly1, poly2);
    printf("\n");
    printf("Added Polynomial is : ");
    display(addPoly);
    return 0;
}
struct node *create(struct node *poly1)
{
    int coeff, expo, n;
    printf("Enter the no. of terms : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d : ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent of term %d : ", i + 1);
        scanf("%d", &expo);
        poly1 = poly(poly1, coeff, expo);
    }
    return poly1;
}
struct node *poly(struct node *poly1, int co, int ex)
{
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = poly1;
    new->coeff = co;
    new->expo = ex;
    new->next = NULL;
    if (poly1 == NULL || ex > poly1->expo)
    {
        new->next = poly1;
        poly1 = new;
    }
    else
    {
        while (ptr->next != NULL && ex < ptr->next->expo)
        {
            ptr = ptr->next;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
    ptr = poly1;
    return poly1;
}
void display(struct node *poly1)
{
    struct node *ptr = poly1;
    while (ptr != NULL)
    {
        printf("%dx^%d ", ptr->coeff, ptr->expo);

        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" + ");
        }
        else
            printf("\n");
    }
}
struct node *add(struct node *addPoly, struct node *poly1, struct node *poly2)
{
    struct node *ptr1 = poly1;
    struct node *ptr2 = poly2;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            addPoly = poly(addPoly, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            addPoly = poly(addPoly, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            addPoly = poly(addPoly, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        addPoly = poly(addPoly, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        addPoly = poly(addPoly, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    return addPoly;
}
