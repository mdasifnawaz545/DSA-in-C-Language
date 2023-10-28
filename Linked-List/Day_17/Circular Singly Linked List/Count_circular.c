#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *tail = malloc(sizeof(struct node));
    tail->data = 786;
    tail->next = tail;

    struct node *current = malloc(sizeof(struct node));
    current->data = 10;
    current->next = tail->next;
    tail->next = current;
    
    


    struct node *p=tail->next;
    do
    {
        printf("%d ",tail->data);
        tail=tail->next;
    } while (p!=tail->next);
    

    return 0;
}