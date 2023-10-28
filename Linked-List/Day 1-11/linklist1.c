// Creating a linked list having 3 nodes.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->link=NULL;    

    struct node* current=(struct node*)malloc(sizeof(struct node));
    current->data=20;
    current->link=NULL;
    
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;

    head->link->link=current;
    
    return 0;
}