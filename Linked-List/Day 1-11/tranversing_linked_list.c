#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void count(struct node *);
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=786;
    scanf("%d",head->data);
    head->link=NULL;

    struct node *current=(struct node*)calloc(1,sizeof(struct node));
    current->data=897;
    current->link=NULL;
    head->link=current;

    current=(struct node*)calloc(1,sizeof(struct node));
    current->data=777;
    current->link=NULL;
    head->link->link=current;


    current=(struct node*)calloc(1,sizeof(struct node));
    current->data=997;
    current->link=NULL;
    head->link->link->link=current;

    count(head);

    return 0;
}
void count(struct node *head)
{
    int counting=0;
    if (head==NULL)
    {
        printf("Linked-List is Empty.");
    }
    struct node *count=head;
    while (count!=NULL)
    {
        counting++;
        count=count->link;
    }
    printf("Number of nodes in the following Linked-List are : %d",counting);
}
