#include <stdio.h>
void add_pos(int a1[], int a2[], int size,int pos,int data);

int main()
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int size = sizeof(a1) / sizeof(int);
        for (int i = 0; i < size; i++)
    {
        printf("%d ",a1[i]);
    }
    int pos = 6, data = 66;
    int a2[size + 1];
    add_pos(a1, a2, size, pos, data);
    return 0;
}
void add_pos(int a1[], int a2[], int size,int pos,int data)
{
    int index=pos-1;
    for (int i = 0; i < index; i++)
    {
        a2[i]=a1[i];
    }
    a2[index]=data;
    int k;
    for (int j = index +1 ,  k=index ; j < size+1, k <size; j++,k++)
    {
        a2[j]=a1[k];
    }
    printf("\n");
    for (int l = 0; l < size+1; l++)
    {
        printf("%d ",a2[l]);
    }
    
    
}