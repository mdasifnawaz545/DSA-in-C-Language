#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void  delete_first(struct node *head);

int main()
{
    struct node* head=malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;

    struct node* current =malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;

    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;

    head->link->link=current;
    
    current=malloc(sizeof(struct node));
    current->data=40;
    current->link=NULL;

    head->link->link->link=current;

    struct node *ptr=head;
    printf("Linked List Before : ");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    delete_first(head);

    return 0;
}
void  delete_first(struct node *head)
{
    struct node *ptr=head;
    head=head->link; 
    // free(ptr);
    ptr=head;
    printf("\nLinked List After : ");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    

}
