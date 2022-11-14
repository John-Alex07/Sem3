#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int info;
    struct Node *next;
}Node;
Node inp(Node **temp)
{
    printf("Enter a number\n");
    scanf("%d",&(*temp)->info);
    (*temp)->next = NULL;
}
Node List(Node **head)
{
    Node *temp = *head;
    printf("Enter 1 to insert Nodes or 0 to Stop.\n-1 to Remove\n");
    int ch;
    scanf("%d",&ch);
    while(ch)
    {
       Node *t = (Node*)malloc(sizeof(Node));
       inp(&t); 
       temp->next = t; 
       printf("Enter 1 to insert Nodes or 0 to Stop.\n-1 to Remove\n");
       scanf("%d",&ch);
       if(ch == -1)
       {
           rem(&temp);
           display(*head);
       }
       if(ch!=-1)
       temp = t;
    }
}
void rem(Node **tem)
{
   (*tem)->next = NULL;
}
int display(Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->info);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    Node *head;
    head = (Node*)malloc(sizeof(Node));
    inp(&head);
    List(&head);
    display(head);
}