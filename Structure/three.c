// Passing pointers to structure as an argumnet.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
    char name[20];
    int roll;
};
void display(struct node *);
int main()
{
    struct node emp={"Mohammad Asif Nawaz" ,22052736};
    display(&emp);
    return 0;
}
void display(struct node *info)
{
    printf("Name : %s and Roll number : %d",info->name,info->roll);
}