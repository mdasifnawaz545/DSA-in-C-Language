#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *addEmpty(struct node *tail);
struct node *addBegin(struct node *tail);
int searching(struct node *tail);
struct node *addEnd(struct node *tail,int data);
int main()
{
    struct node *tail = NULL;
    tail = addEmpty(tail);
    tail = addBegin(tail);
    tail = addEnd(tail,20);
    tail = addEnd(tail,30);
    tail = addEnd(tail,40);
    tail = addEnd(tail,50);
    tail = addEnd(tail,60);
    struct node *ptr=tail->next;
    do
    {
       printf("%d ",ptr->data);
       ptr=ptr->next;
    } while (ptr!=tail->next);
    int search;
    search=searching(tail);
    printf("%d",search);
    return 0;
}
struct node *addEmpty(struct node *tail)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = 10;
    temp->next = temp;
    return temp;
}
struct node *addBegin(struct node *tail)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = 786;
    temp->next = tail->next;
    tail->next = temp;
    return tail;
}
struct node *addEnd(struct node *tail,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return tail;
}
int searching(struct node *tail)
{
    int index=1,element;
    printf("Enter the element You want to search : ");
    scanf("%d",&element);
    struct node *ptr=tail->next;
    if (tail==NULL)
    {
        return -2;
    }
    else
    {
        do
        {
            if (ptr->data==element)
            {
                return index;
            }
            index++;
            ptr=ptr->next;
            
        } while (ptr!=tail->next);
        
    }
    return -1;
}