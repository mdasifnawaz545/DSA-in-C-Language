// Passing array of structure as argument.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
    char name[20];
    int roll;
    int age;
};
void read(struct student s[], int n);
int main()
{
    int n;
    printf("Enter the no. of student : ");
    scanf("%d", &n);
    struct student s[n];
    read(s, n);
    return 0;
}
void read(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter the name : ");
        gets(s[i].name);
        printf("Enter the roll : ");
        scanf("%d", &s[i].roll);
        printf("Enter the age : ");
        scanf("%d", &s[i].age);
    }
    for (int j = 0; j < n; j++)
    {
        printf("Name : %s", s[j].name);
        printf("Roll : %d", s[j].roll);
        printf("Age : %d", s[j].age);
    }
}