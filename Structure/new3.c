// Returning a pointer to a structure from the function.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    char name[20];
    int roll;
    int age;
};
struct student *display(struct student *s1);
int main()
{
    struct student s1;
    struct student *s;
    s=display(&s1);
    printf("Name : %s ,Roll No. : %d , Age : %d.",s->name,s->roll,s->age);
    return 0;
}
struct student* display(struct student *s1)
{
    printf("Enter the name : ");
    gets(s1->name);
    printf("Enter your roll : ");
    scanf("%d",(s1->roll));
    printf("Enter your age : ");
    scanf("%d",(s1->age));
    return &s1;
}