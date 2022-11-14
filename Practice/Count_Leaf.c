#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
   int data;
   struct Tree *left, *right;
}Node;
Node *Create_Node(Node *node, int n)
{
    node = (Node*)malloc(sizeof(Node));
    node->data = n;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node *Add_Node(Node *root, int n)
{
   if(root == NULL)
   {
       root = Create_Node(root, n);
       return root;
   }
   else
   if(root->data > n)
     root->left = Add_Node(root->left, n);
   else
     root->right = Add_Node(root->right, n);    
    
    return root;
}
int count_Leaf(Node *root, int n)
{
     if(root == NULL)
    return n;
    if(root->left == NULL && root->right == NULL)
        n++;
    n = count_Leaf(root->left, n);
    n = count_Leaf(root->right, n);
}
void print_Inorder(Node *root)
{
    if(root == NULL)
    return;
    print_Inorder(root->left);
    printf("%d ",root->data);
    print_Inorder(root->right);
}
int main()
{
  Node *root = NULL;
  root = Add_Node(root, 14);
  root = Add_Node(root, 20);
  root = Add_Node(root, 6);
  print_Inorder(root);
}
