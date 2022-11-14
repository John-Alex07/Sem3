#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;
int init()
{
    int n;
    scanf("%d", &n);
    return n;
}
Node *create_node( Node *node, int n)
{
   node = (Node*)malloc(sizeof(Node));
   node->data = n;
   node->next = NULL;
   return node; 
}
int main()
{
  Node *head = NULL;
  Node *ptr = NULL;
  int ch;
  while (1)
  {
     printf("Enter Choice\n");
     scanf("%d",&ch);
     if(ch == 1)
     {
         if(head == NULL)
         {    
             head = create_node(head, init());
             ptr = head;
         }
         else
         {
             ptr->next = create_node(ptr->next, init());
             ptr = ptr->next; 
         }
     }
     else
     if(ch == 2)
     {
         while(head != NULL)
         {
             printf("%d\n", head->data);
             head = head->next;
         }
     }
     else
     exit(0);
  }
  
}