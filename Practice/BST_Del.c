#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right
}Node;
int init()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    return n;
}
void create(Node **temp, int n)
{
    *temp = (Node*)malloc(sizeof(Node));
    (*temp)->data = n;
    (*temp)->left = NULL;
    (*temp)->right = NULL;
}
void Tree(Node **root, int n)
{
    if(*root == NULL)
        create(root, n);
    else
    if((*root)->data > n)
        Tree(&(*root)->left, n);
    else
        Tree(&(*root)->right, n);
    return;
}
Node *Min_Node(Node *root)
{
    if(root == NULL)
    return;
    else
    Min_Node(root->left);

    return root;
}
Node *BST_Del(Node *root, int n)
{
    if(root == NULL)
    return;
    else
    if(root->data > n)
    root->left = BST_Del(root->left, n);
    else
    if(root->data < n)
    root->right = BST_Del(root->right, n);
    else
    {
       if(root->left == NULL && root->right == NULL)
           {
               free(root);
               root = NULL;
               return root;
           }
        else
        if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else
        if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            Node *min = Min_Node(root->right);
            root->data = min->data;
            root->right = BST_Del(root->right, min->data);
            return root;
        }
    }
}
void display(Node *root)
{
   if(root == NULL)
   return;
   display(root->left);
   printf("%d", root->data);
   display(root->right);
}
int main()
{
   Node *root = NULL;
   create(&root, init());
   Node *t = root;
   Tree(&t, init());
   Tree(&t, init());
   Tree(&t, init());
   Tree(&t, init());
   Tree(&t, init());
   display(root);
}