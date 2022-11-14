#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Tree;
int init()
{
    int n;
    printf("\nEnter a number : ");
    scanf("%d",&n);
    return n;
}
Tree *seed(int n)
{
    Tree *Leaf = (Tree*)malloc(sizeof(Tree));
    Leaf->data = n;
    Leaf->left = NULL;
    Leaf->right = NULL;
    return Leaf;
}
void create_BST(Tree **root, int n)
{
   if(*root == NULL)
      *root = seed(n);
    else
    if((*root)->data >= n)
      create_BST(&(*root)->left, n);
    else
      create_BST(&(*root)->right, n);
    return;
}
void display(Tree *root)
{
    if(root == NULL)
    return;
    display(root->left);
    printf("%d", root->data);
    display(root->right);
}
bool Search(Tree *root, int n)
{
    if(root != NULL && root->data == n)
    return true;
    else
    if(root != NULL && root->data >= n)
    return Search(root->left, n);
    else
    if(root != NULL && root->data < n)
    return Search(root->right, n);
    
    return false;
}
Tree *Parent_Srch(Tree *root, int n)
{
    Tree* P;
    if(root->data == n || root == NULL)
    return NULL;
    else
    if(root->data > n)
        {
           P = Parent_Srch(root->left, n);
        }
    else
        {
           P = Parent_Srch(root->right, n);
        }
    if(P == NULL)
    {
        P = root;
        return P;
    }
}
int main()
{
    Tree *root = NULL;
    create_BST(&root, init());
    Tree *t = root;
    create_BST(&t, init());
    create_BST(&t, init());
    create_BST(&t, init());
    create_BST(&t, init());

    display(root);
    if(Search(root, init()))
    printf("\nEXISTS");
    else
    printf("\nDOESN'T EXISTS");

    Tree *parnt = (Tree*)malloc(sizeof(Tree));
    parnt = Parent_Srch(root, init());
    if(parnt != NULL)
    printf("%d", parnt->data);
    else
    printf("NO PARENT Exists ");
}