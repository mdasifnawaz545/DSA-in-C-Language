#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=786;
    head->link=NULL;

    struct node* current=malloc(sizeof(struct node));
    current->data=777;
    current->link=NULL;

    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=999;
    current->link=NULL;

    current=malloc(sizeof(struct node));
    current->data=545;
    current->link=NULL;

    add(head,current);

    return 0;
}