#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    float coeff;
    int expo;
    struct node *link;
};
struct node * create(struct node *head);
struct node * sortPol(struct node *head,int co,int ex);
void display (struct node *head);
int main()
{
    struct node *head=NULL;
    printf("Enter the Polynomial\n");
    head=create(head);
    display(head);
    return 0;
}
struct node * create(struct node *head)
{
    int n,i,expo,coeff;
    printf("Enter the no. of terms : ");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter the Coefficient of term %d : ",i+1);
        scanf("%d",&coeff);
        printf("Enter the Exponent of term %d : ",i+1);
        scanf("%d",&expo);
        head=sortPol(head,expo,coeff);

    }
    return head;
}
struct node *sortPol(struct node *head,int ex,int co)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->coeff=co;
    ptr->expo=ex;
    ptr->link=NULL;

    if (head==NULL || ex > head->expo)
    {
        ptr->link=head;
        head=ptr;
    }
    else
    {
        struct node *temp=head;
        while (temp->link!=NULL && ex<temp->link->expo)
        {
            temp=temp->link;
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
    return head;
}
void display (struct node *head)
{
    if (head==NULL)
    {
        printf("There is No Polynomial.");
    }
    else
    {
        struct node *temp=head;
        while (temp!=NULL)
        {
            printf("%.1fX^%d",temp->coeff,temp->expo);
            temp=temp->link;
            if (temp!=NULL)
            {
                printf(" + ");
            }
            else printf("\n");
            
        }
        
    }
}