//JOHN ALEXANDER E 20011896
#include <stdio.h>
#include <stdlib.h>
int c = -1;
int push(int *p)
{
    int v;
    if (p == NULL)
        printf("Stack Filled!!\n");
    else
    {
        printf("Enter a number\n");
        scanf("%d", &v);
        c++;
        p = realloc(p,c+1);
        printf("Pushed : %d\n\n", v);
        p[c] = v;
    }
}
int pop(int *p)
{
    if (c == -1)
        printf("Stack Empty!!\n\n");
    else
    {   
        printf("Popped : %d\n\n",p[c]);
        p = (int*)realloc(p,c+1);
        c--;
    }
}
int print_stack(int *a)
{
    for(int i=0;i<=c;i++)
    printf("%d ",a[i]);
}
int main()
{
    int *a = (int*)malloc(sizeof(int));
    int p = -1;
    while (p != 0)
    {
        printf("\nEnter 1 to PUSH\n");
        printf("Enter 2 to POP\n");
        if(c!=-1)
        printf("Enter 3 to Print the Stack\n");
        printf("Enter 0 to Stop\n");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            push(a);
            break;
        case 2:
            pop(a);
            break;
        case 3:
            print_stack(a);
            break;
        case 0:
             free(a);
             continue;
        default:
            printf("INVALiD CHOICE\n");
        }
    }
    return 0;
}
