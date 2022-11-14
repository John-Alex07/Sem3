#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
    int data;
    struct List *next;
}Node;
Node *input()
{
    Node *t = (Node*)malloc(sizeof(Node));
    printf("Enter a number\n");
    scanf("%d",&t->data);
    t->next = NULL;
    return t;
}
Node List(Node **head)
{
   *head = input();
   while(1)
    {
        printf("Enter a number\n",)
}
int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    List(&head);
}