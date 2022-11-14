#include <stdio.h>
struct number 
{        
    int data;
};
int push(struct number *p, int *t)
{
    int v;
    if (*t == 10)
        printf("Stack Filled!!\n");
    else
    {
        (*t)++;
        printf("Enter a number\n");
        scanf("%d", &v);
        (p+*t)->data = v;
        printf("Pushed : %d\n\n", v);
    }
}
int pop(struct number *p, int *t)
{
    if (*t == -1)
        printf("Stack Empty!!\n");
    else
    {
        printf("Popped : %d\n\n",(p+*t)->data);
        (p+*t)->data = 0;
        (*t)--;
    }
}
int display(int *a,int *t)
{
    for(int i=0;i<=*t;i++)
    printf("%d ",a[i]);
}
void main()
{
     struct number arr[10];
        int top=-1;
    int p = -1;
    while (p != 0)
    {
        printf("\nEnter 1 to PUSH\n");
        printf("Enter 2 to POP\n");
        if(top!=-1)
        printf("Enter 3 to Print the Stack\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            push(arr, &top);
            break;
        case 2:
            pop(arr,&top);
            break;
        case 3:
            display(arr,&top);
            break;
        case 0:
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
    return 0;
}