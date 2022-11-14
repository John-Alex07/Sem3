/*JOHN ALEXANDER E 20011896*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int front;
    int rear;
    int n;
    int *arr;
}Queue;
Queue ini(Queue Q)
{
   printf("Enter the size\n");
   scanf("%d",&Q.n);
   Q.front = Q.rear = -1;
   Q.arr = (int*)malloc(Q.n*sizeof(int));
   return Q;
}
Queue enqueueF(Queue Q, int num)
{
   if(Q.front == -1 && Q.rear != -1)
       printf("QUEUE OVERFLOW FROM FRONT\n");
    else
    {
        printf("Enter a number\n");
            scanf("%d",&num);
        if(Q.front == -1)
        {
            Q.front = 0;
            Q.rear = 0;
        }
        Q.arr[Q.front] = num;
        Q.front--;
    }
    return Q;
}
Queue enqueueR(Queue Q, int num)
{
   if(Q.rear == Q.n-1)
     printf("QUEUE OVERFLOW FROM REAR\n");
    else
    {
        printf("Enter a number\n");
            scanf("%d",&num);
         Q.rear++;
        Q.arr[Q.rear] = num;
    }
    return Q;
}
Queue dequeueF(Queue Q)
{
    if(Q.front == Q.rear)
    printf("QUEUE EMPTY\n");
    else
    {
        Q.front++;
    }
    return Q;
}
Queue dequeueR(Queue Q)
{
    if(Q.front == Q.rear)
    printf("QUEUE EMPTY");
    else
    {
        Q.rear--;
    }
    return Q;
}
void display(Queue Q)
{
    printf("FRONT -> %d\n",Q.front);
    for(int i = Q.front+1; i<=Q.rear; i++)
    printf("%d ",Q.arr[i]);
    printf("\nREAR -> %d\n",Q.rear);
}
int main()
{
    printf("JOHN ALEXANDER E 20011896\n");
    int q;
    Queue Q;
    Q = ini(Q);
     int p = -2,num;
        printf("Enter 100 for Input Restriction from FRONT end\n");
        printf("Enter 101 for Input Restriction from REAR end\n");
        printf("Enter 10 for Output Restriction from FRONT end\n");
        printf("Enter 11 for Output Restriction from REAR end\n");
        printf("Enter any other number for no Restriction\n");
        scanf("%d",&q);
    while (p != 0)
    {   
        if(q!=100)
        printf("\nEnter 1 to Input to the Front of the Queue\n");

        if(q!=101)
        printf("Enter 2 to Input to the Rear of the Queue\n");
        
        if(q!=10)
        printf("Enter 3 to Delete from the Front of the Queue\n");
        
        if(q!=11)
        printf("Enter 4 to Delete from the Rear of the Queue\n");
        
        printf("Enter 5 to Print the Queue\n");
        printf("Enter -1 to RESET QUEUE\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            if(q==100)
            {
              printf("INVALID CHOICE\n");
              break;
            }
            Q = enqueueF(Q,num);
            break;
        case 2:
           if(q==101)
            {
              printf("INVALID CHOICE\n");
              break;
            }
            Q = enqueueR(Q,num);
            break;
        case 3:
            if(q==10)
            {
              printf("INVALID CHOICE\n");
              break;
            }
            Q = dequeueF(Q);
            break;
        case 4:
           if(q==11)
            {
              printf("INVALID CHOICE\n");
              break;
            }
            Q = dequeueR(Q);
            break;
        case 5:
            display(Q);
            break;
        case -1 :
            Q = ini(Q);
            break;
        case 0:
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
}
