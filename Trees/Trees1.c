#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *create();
void preorder(struct node *root);
void Inorder(struct node *root);
void Postorder(struct node *root);
int main()
{
    struct node *root = NULL;
    root = create();
    // printf("Trees Data In Preorder is : ");
    // preorder(root);
    printf("\nTrees Data In Inorder is : ");
    Inorder(root);
    // printf("\nTrees Data In Postorder is : ");
    // Postorder(root);
    return 0;
}
struct node *create()
{
    int val;
    struct node *newNode = malloc(sizeof(struct node));
    printf("Enter Data (Enter -1 to Exit) : ");
    scanf("%d", &val);
    if (val == -1)
    {
        return 0;
    }
    else
    {
        newNode->data = val;
        printf("Enter Left Child of %d Node\n", val);
        newNode->left = create();
        printf("Enter Right Child of %d Node\n", val);
        newNode->right = create();
    }
    return newNode;
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void Inorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Postorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else 
    {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}