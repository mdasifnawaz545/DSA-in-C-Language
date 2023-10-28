#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    char ch;
    struct node *next;
};
struct node *addEmpty(char c, struct node *tail);
void palin_check(struct node *tail, int count);
int check(int index, int count);
void display(struct node *tail);
int main()
{
    struct node *tail = NULL;
    tail = addEmpty('m', tail);
    tail = addEmpty('a', tail);
    tail = addEmpty('d', tail);
    tail = addEmpty('a', tail);
    tail = addEmpty('m', tail);
    struct node *ptr = tail->next;
    int count = 0;
    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != tail->next);

    display(tail);
    palin_check(tail, count);
    return 0;
}
struct node *addEmpty(char c, struct node *tail)
{
    struct node *temp = malloc(sizeof(struct node));
    if (tail == NULL)
    {
        temp->ch = c;
        temp->prev = temp;
        temp->next = temp;
        tail = temp;
    }
    else
    {
        struct node *ptr = tail->next;
        do
        {

            ptr = ptr->next;
        } while (ptr != tail->next);
        temp->ch = c;
        temp->prev = tail;
        temp->next = tail->next;
        tail->next = temp;
        tail = tail->next;
    }
    return tail;
}
void display(struct node *tail)
{
    struct node *ptr = tail->next;
    do
    {
        printf("%c ", ptr->ch);
        ptr = ptr->next;
    } while (ptr != tail->next);
}
void palin_check(struct node *tail, int count)
{
    struct node *head1 = tail->next;
    struct node *head2 = tail;
    int index = 0;
    do
    {
        if (head1->ch == head2->ch)
        {
            index++;
            head1 = head1->next;
            head2 = head2->prev;
        }
    } while (head1 != tail->next);
    int c=check(index, count);
    if (c==0)
    {
        printf("Not Palindrome.");
    }
    
}
int check(int index, int count)
{
    if (count==index)
    {
        printf("Palindrome string.");
    }
    else return 0;
    
}