#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct List
{
    int data;
    struct List *next;
}List;
void MoveNode(List** head2, List** head1)
{
    List* newNode = *head1;
    assert(newNode != NULL);
    *head1 = newNode->next;
    newNode->next = *head2;
    *head2 = newNode;
}
List* SortedMerge(List* a, List* b)
{
    List t;
 
    List* tail = &t;
    t.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(t.next);
}
void push(List** headT, int new_data)
{
    List* new_node =
        (List*) malloc(sizeof(List));
    new_node->data  = new_data;
    new_node->next = (*headT);
 
    (*headT)  = new_node;
}
void display(List *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void swap(List *a, List *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void bubbleSort(List **start)
{
    int swapped, i;
    List *ptr1;
    List *lptr = NULL;
    if (*start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = *start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
int menu()
{
    printf("MENU :\n");
    printf("1. Add a Node\n");
    printf("0. Exit\n");
    int n;
    printf("Enter your choice\n");
    scanf("%d",&n);
    return n;
}
List *create(List *l)
{
   int n = menu();
    int num;
    while(n)
    {
        if(n == 1)
        {
            printf("Enter a number\n");
            scanf("%d",&num);
            push(&l, num);
        }
        if(n == 2)
        {
           printf("LIST : \n");
           display(l);
           printf("\n");
        }
        printf("Enter 1, 2 or 0 : ");
        scanf("%d",&n);
    }
  return l;
}
int main()
{
    List* res = NULL;
    List* a = NULL;
    List* b = NULL;
    
    printf("LIST 1 : \n");
    a = create(a);
    bubbleSort(&a);
   
    printf("LIST 2 : \n");
    b = create(b);
    bubbleSort(&b);
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    display(res);
 
    return 0;
}