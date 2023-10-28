// Passing pointers to structure as an argumnet.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    char name[20];
    int roll;
    int age;
};
void display(struct student *s1);
int main()
{
    struct student s1={"MOHAMMAD ASIF NAWAZ",22052736,20};
    display(&s1);
    return 0;
}
void display(struct student *s1)
{
    printf("Name : %s ,Roll No. : %d , Age : %d.",s1->name,s1->roll,s1->age);
}