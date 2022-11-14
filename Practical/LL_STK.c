#include<stdio.h> 
#include<stdlib.h>
#define max 5
struct Node
{
    int data;
    struct Node *next;

};
typedef struct Node node;

void insert(node **,int,int*);
void delete(node**,int*);
void display(node *top);
 int main() 
 {
 node *top;
int counter=0,choice,value,pos,sizeRef=-1;

top=NULL;
while(counter==0)
{

printf("1.INSERT  \n2.DELETE  \n3.DISPLAY \n4.EXIT\n");
scanf("%d",&choice);

switch(choice)
{
case 1:
if(sizeRef==max-1)
{
printf("Stack is Full\n");
}
else{
printf("Enter a value : ");
scanf("%d",&value);
insert(&top,value,&sizeRef);
}
break;

case 2:
if(sizeRef==-1)
{
printf("Stack is Empty\n");
}
else{
delete(&top,&sizeRef);
}
break;

case 3:
display(top);
break;

case 4:
printf("EXITED\n");
counter++;
break;

default:
printf("WRONG CHOICE\n");
break;
}
}
 return 0; 
 } 

void insert(node **top,int value,int *sizeRef)
{
*sizeRef=*sizeRef+1;
node *temp=(node*)malloc(sizeof(node));
temp->data=value;
temp->next=*top;
*top=temp;

}

void display(node *top)
{
node *temp;
temp=top;
printf("List is : ");
while(temp!=NULL)
{
printf(" %d ",temp->data);
temp=temp->next;
}
printf("\n");
}

void delete(node**top,int *sizeRef)
{
if (top == NULL) 
        return; 

*sizeRef=*sizeRef-1;
node *temp=*top;
printf("%d Deleted Successfully\n",temp->data);
*top=temp->next;
free(temp);
}