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
    Q->front = -1;
    Q->rear = -1;
    printf("Enter the size\n");
    scanf("%d",&Q->n);
    Q->arr = (int*)malloc(Q->n*sizeof(Q->arr));
}
Queue *enqueue(Queue *Q,int num)
{
    if((Q->n) == Q->rear)
    printf("QUEUE OVERFLOW\n");
    else
    {
       if(Q->front == -1 && Q->rear == -1)
        {
         Q->front = 0;
         Q->rear = 0;
        }
        printf("Enter a number\n");
            scanf("%d",&num);
        Q->arr[Q->rear] = num;
        Q->rear++;
    }
}
Queue *dequeue(Queue *Q)
{
    if(Q->rear == Q->front && Q->front != 0)
    printf("QUEUE UNDERFLOW\n");
    else
    {
        printf("DELETED ELEMENT : %d",Q->arr[Q->front]);
        Q->front++;
    }
}
Queue display(Queue *Q)
{
    printf("QUEUE : \n");
    for(int i = Q->front; i<Q->rear;i++)
      printf("%d ",Q->arr[i]);
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
        if(Q->rear!=Q->front)
        printf("Enter 3 to Print the Stack\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            enqueue(Q,num);
            break;
        case 2:
            dequeue(Q);
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