#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
Node *stack(int n)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}
Node *push(int n, Node **top)
{
   Node *temp = stack(n);
   temp->next = *top;
   *top = temp;
   return temp;
}
Node *pop(Node **top, Node *ptr_free)
{
    *top = (*top)->next;
    free(ptr_free);
    return *top;
}
void display(Node *trav)
{
   if(trav != NULL)
      display(trav->next);
   else
      return;
    
    printf("%d ",trav->data);
}
int main()
{
    Node *ptr;
    Node *top = NULL;
    ptr = push(5, &top);
    ptr = push(7, &top);
    ptr = push(1, &top);
    ptr = push(8, &top);
    ptr = pop(&top, ptr);
    ptr = pop(&top, ptr);
    display(top);
}