#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}List;
int menu()
{
    printf("MENU :\n");
    printf("1. Push a Node\n");
    printf("2. Pop a Node\n");
    printf("3. Display\n");
    printf("0. Exit\n");
    int n;
    printf("Enter your choice\n");
    scanf("%d",&n);
    return n;
}
void create_Node(List **temp)
{
    int n;
    *temp = (List*)malloc(sizeof(List));
    printf("Enter a number\n");
    scanf("%d",&n);
    (*temp)->data = n;
    (*temp)->next = NULL;
}
void display(List *head)
{
    printf("LIST : ");
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
/*void create_List(List **head)
{
    int ch;
    create_Node(head);
    printf("HEAD NODE CREATED..\n");
    List *temp = *head;
   printf("Enter 1 to Add a Node\n");
   printf("Enter 0 to Stop\n");
   scanf("%d",&ch);
   while(ch)
   {
     create_Node(&(temp->next));
     temp = temp->next;
     printf("Enter 1 or 0 : ");
     scanf("%d",&ch);
   }
}*/
List *push(List *put)
{
    put = put->next;
    create_Node(&(put->next));
    return put;
}
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}  
void create_List(List **head)
{
    int ch;
    create_Node(head);
    List *temp = *head;
    List *ptr = *head;
    printf("HEAD NODE CREATED..\n");
    ch = menu();
    while(ch)
    {
        switch (ch)
    {
    case 1:
        temp = push(temp);
        break;
    case 2:
        temp = pop(temp, ptr);
        ptr = *head;
        while(ptr->next != temp)
        ptr = ptr->next;
        break;
    case 3:
        display(*head);
        break;
    default:
        printf("ENTER A VALID OPTION\n");
        break;
    }
    ch = menu();
    }
}
int main()
{
  List *head = NULL;
  create_List(&head);
  display(head);
  int n = menu();
}