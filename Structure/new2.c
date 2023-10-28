//Returning a structure variable from a function. Why pointer is not work here quite well.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    char name[20];
    int roll;
    int age;
};
struct student display(struct student s1);
int main()
{
    struct student s1={"MOHAMMAD ASIF NAWAZ",22052736,20};
    struct student s;
    s=display(s1);
    printf("Name : %s ,Roll No. : %d , Age : %d.",s.name,s.roll,s.age);
    return 0;
}
struct student display(struct student s1)
{
    return s1;
}