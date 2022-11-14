#include<stdio.h> 
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *prev;
   struct Node *next;
};

typedef struct Node node;

void insert(node **,node**,int value);
void PalindromeCheck(node *,node*);

 int main() 
 {
    int num,value;
    node *head=NULL,*tail=NULL;
    printf("Enter the total number of nodes to enter : ");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
       printf("Enter node %d data: ",(i+1));
       scanf("%d",&value);
       insert(&head,&tail,value);  
    }
    PalindromeCheck(head,tail);
    

 return 0; 
 } 

 void insert(node **head,node **tail, int value)
 {
 node *temp=(node*)malloc(sizeof(node));
 temp->data=value;
 temp->prev=temp->next=NULL;
 if(*head==NULL&&*tail==NULL)
{
   *head=temp;
   *tail=temp;
}
else
{
   (*tail)->next=temp;
   temp->prev=*tail;
   *tail=temp;
}
}

void PalindromeCheck(node *head,node *tail)
{
   int counter=0;
   while(head->next!=NULL||tail->prev!=NULL)
   {
      if(head->data!=tail->data)
      {
         counter++;
         break;
      }
      head=head->next;
      tail=tail->prev;
   }
   if(counter)
      printf("Not in Palindrome Form\n");
   else 
      printf("In Palindrome Form\n");
}