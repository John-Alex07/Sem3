#include <stdio.h>
typedef struct counters
{
    int s;
    int rear;
    int n;
}count;
typedef struct Queue
{
    int data;
    int priority;
}Que;
int ini(count *c)
{
    c->rear = -1;
    c->s = 0;
}
int enqueue(Que *Q, count *c)
{
    int d,p;
    if(c->rear == c->n-1)
    printf("QUEUE OVERFLOW\n");
    else
    {
      printf("Enter the number and its priority\n");
      scanf("%d%d",&d,&p);
       ++(c->rear);
      Q[c->rear].data = d;
      Q[c->rear].priority = p;
    }
}
int min_priority(Que *Q, count *c)
{
    int x;
    c->s = Q[0].priority;
    for(int i = 1;i<=c->rear;i++)
        if(c->s > Q[i].priority)
          {
              c->s = Q[i].priority;
              x = i;
          }
    return x;
}
int dequeue(Que *Q, count *c)
{
    if(c->rear == -1)
    printf("QUEUE UNDERFLOWS\n");
    else
    {
        int t = min_priority(Q,c);
        while(t < c->n-1)
        {
            Q[t] = Q[t+1];
            t++;
        }
        c->rear--;
    }
}
int display(Que *Q, count *c)
{
    for(int i = 0;i<=c->rear;i++)
    printf("DATA : %d\nPRIORITY : %d\n",Q[i].data,Q[i].priority);
}
int main()
{
    count c;
    printf("Enter the size of queue\n");
    scanf("%d",&c.n);
    Que Q[c.n];
    ini(&c);
    
    int ch;
    while(ch!=4)
    {
      printf("Enter 1 to Input Data into the Queue\n");
      printf("Enter 2 to Delete from Queue\n");
      printf("Enter 3 to Display\n");
      printf("Enter 4 to STOP\n");
      printf("Enter your choice\n");
       scanf("%d",&ch);
      switch(ch)
      {
        case 1:
        enqueue(Q,&c);
        break;
        case 2:
        dequeue(&Q,&c);
        break;
        case 3:
        display(Q,&c);
        break;
        case 4:
        continue;
        default:
        printf("INVALID CHOICE\n");
       }
    }
}