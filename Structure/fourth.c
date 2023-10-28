// Returning a structure variable from a function. Why pointer is not work here quite well.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct st{
    char name[20];
    int roll;
};
struct st read(struct st);
int main()
{
    struct st s;
    struct st emp;
    emp=read(s);
    printf("%s  %d",emp.name,emp.roll);
    return 0;
}
struct st read(struct st info)
{
    printf("Enter the Name : ");
    gets(info.name);
    printf("Enter the roll number : ");
    scanf("%d",&(info.roll));
    return info;
}