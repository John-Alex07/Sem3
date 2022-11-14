#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Link;
Link *create_Node(Link *node)
{
   node = (Link*)malloc(sizeof(Link));
   printf("Enter the number\n");
   scanf("%d",&node->data);
   node->next = NULL;
   return node;
}
void node_right(Link **temp)
{
   int c = 0;
   printf("Enter 1 to Add a Node or 0 to Stop\n");
   scanf("%d",&c);  
    while(c)
    {
        Link *t = create_Node(t);
        (*temp)->next = t;
        *temp = t;
        printf("Enter 1 or 0 : ");
        scanf("%d",&c);
    }
}
void node_left(Link **temp)
{
     int c = 0;
     printf("Enter 1 to Add a Node or 0 to Stop\n");
     scanf("%d",&c); 
    while(c)
    {
      Link *t = create_Node(t);
      t->next = *temp;
      *temp = t;
      printf("Enter 1 or 0 : ");
      scanf("%d",&c); 
    }
}
void display(Link *head)
{
    while(head != NULL)
    {
        printf("%d",head->data);
        head = head->next;
    }
}
Link *create_List(Link *head)
{
    int ch;
  head = create_Node(head);
  Link *temp = head;
  printf("MENU :\n");
  printf("1. Add Nodes to Right\n");
  printf("2. Add Nodes to Left\n");
  printf("ENTER YOUR CHOICE : ");
  scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        node_right(&temp);
        break;
        case 2:
        node_left(&head);
        break;
    }
    return head;
}
void Del_Alt(Link *head)
{
    Link *h = head;
    Link *nxt = head->next;
    while(h != NULL && nxt != NULL)
      {
        h->next = nxt->next;
        h = nxt->next;
        if(h != NULL)
        nxt = h->next;
       }
    printf("\nALTERNATE LINKED LIST : ");
    display(head);
}
int main()
{
    Link *head;
    head = create_List(head);
    printf("LINKED LIST : ");
    display(head);
    Del_Alt(head);
}