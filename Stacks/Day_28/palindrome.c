#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    char ch;
    struct node *next;
};
struct node *addEmpty(char c, struct node *tail);
struct node *addEnd(char c, struct node *tail);
void palindrome_checker(int count, struct node *tail);
void result(int index, int count);
int main()
{
    struct node *tail = NULL;
    tail = addEmpty('a', tail);
    tail = addEnd('b', tail);
    tail = addEnd('s', tail);
    tail = addEnd('a', tail);
    struct node *ptr = tail->next;
    int count = 0;
    do
    {
        count++;
        printf("%c ", ptr->ch);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n");
    palindrome_checker(count, tail);

    return 0;
}

struct node *addEmpty(char c, struct node *tail)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->ch = c;
    temp->next = temp;
    temp->prev = temp;
    tail = temp;
    return tail;
}
struct node *addEnd(char c, struct node *tail)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->ch = c;
    temp->next = tail->next;
    temp->prev = tail;
    tail->next = temp;
    tail = tail->next;
}
void palindrome_checker(int count, struct node *tail)
{
    struct node *head = tail->next;
    struct node *head2 = tail;
    int index = 0;
    do
    {
        if (head->ch == tail->ch)
        {
            index++;
            head = head->next;
            tail = tail->prev;
        }

    } while (head != head2->next);
    result(index, count);
}
void result(int index, int count)
{
    if (index == count)
    {
        printf("It is a Palindrome String.");
    }
    else
    {
        printf("It is not a Palindrome String.");
    }
}