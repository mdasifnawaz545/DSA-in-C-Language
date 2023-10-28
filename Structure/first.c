// Passsing a Structure member as an argumert.
#include<stdio.h>
struct student{
    char name[20];
    int roll_no;
    float marks;
};
void send(char* [],int* , float*);
int main()
{
    struct student s;
    printf("Enter the name : ");
    gets(s.name);
    printf("Enter the roll number of the student : ");
    scanf("%d",&s.roll_no);    
    printf("Enter the marks of the student : ");
    scanf("%f",&s.marks);
    send(&s.name,&s.roll_no,&s.marks);
    return 0;
}
void send(char* name[20],int* roll, float* mark)
{
    printf("%s %d %.2f\n",name,*roll,*mark);
}
