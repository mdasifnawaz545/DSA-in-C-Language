// Passing Structure variable as an argument.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct employee{
    char symbol;
    int id;
    float salary;
};
void display(struct employee *, struct employee *);
int main()
{
    struct employee emp1;
    struct employee emp2;
    emp1.symbol='A';
    emp1.id=01;
    emp1.salary=87342.89;
    emp2.symbol='B';
    emp2.id=02;
    emp2.salary=73842.89;
    display(&emp1,&emp2);
    return 0;
}
void display(struct employee *e1, struct employee *e2)
{
    printf("%c  %d  %.2f\n",e1->symbol,e1->id,e1->salary);
    printf("%c  %d  %.2f\n",e2->symbol,e2->id,e2->salary);
}