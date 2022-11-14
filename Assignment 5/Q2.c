#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int front;
    int rear;
    int n;
    int *arr;
}Queue;
Queue *ini(Queue *Q )
{
    Q->front =-1;
    Q->rear = -1;
    printf("Enter the size\n");
    scanf("%d",&Q->n);
    Q->arr = (int*)malloc(Q->n*sizeof(Q->arr));
}
int isFull(Queue *Q) 
{
  if ((Q->front == Q->rear + 1) || (Q->front == 0 && Q->rear == Q->n - 1)) 
  return 1;
  return 0;
}

int isEmpty(Queue *Q)
 {
  if (Q->front == -1)
   return 1;
  return 0;
}

void enQueue(Queue *Q) 
{ 
    if (isFull(Q))
      printf("\n Queue is full!! \n");
     else  
     {
        int element;
        printf("Enter the element\n");
        scanf("%d",&element);

       if (Q->front == -1) 
       Q->front = 0;
       Q->rear = (Q->rear + 1) % Q->n;
       Q->arr[Q->rear] = element;
       printf("\n Inserted -> %d", element);
     }
}

int deQueue(Queue *Q) 
{
  int element;
     if (isEmpty(Q)) 
     {
      printf("\n Queue is empty !! \n");
      return -1;
     } 
  else 
  {
    element = Q->arr[Q->front];
    if (Q->front == Q->rear) 
    {
      Q->front = -1;
      Q->rear = -1;
    } 
    else 
    {
      Q->front = (Q->front + 1) % Q->n;
    }
    printf("\n Deleted element -> %d \n", element);
    return element;
  }
}
void display(Queue *Q) {
  int i;
  if (isEmpty(Q))
    printf(" \n Empty Queue\n");
  else 
  {
    
    printf("\n Front -> %d ", Q->front);
    printf("\n Items -> ");

    for (i = Q->front; i != Q->rear; i = (i + 1) % Q->n) 
      printf("%d ", Q->arr[i]);
    printf("%d ", Q->arr[i]);
    printf("\n Rear -> %d \n", Q->rear);
  }
}
int main()
{
    int num;
   Queue *Q = (Queue*)malloc(sizeof(Q));
     ini(Q);
    int p = -1;
    while (p != 0)
    {
        printf("\nEnter 1 to Enter Queue\n");
        printf("Enter 2 to Delete Queue\n");
        printf("Enter 3 to Print the Queue\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            enQueue(Q);
            break;
        case 2:
            deQueue(Q);
            break;
        case 3:
            display(Q);
            break;
        case 0:
             free(Q);
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
    return 0;

}