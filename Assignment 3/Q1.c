#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isArmstrong(int n)
{
    int t = n,s=0,r;
    while(t>0)
    {
       r = t%10;
       s = s + r*r*r;
       t = t/10;
    }
    if(n == s)
    return 1;
    else
    return 0;
}
int main()
{
    printf("JOHN ALEXANDER E 20011896\n");
    int num;
    printf("Enter the number of inputs\n");
    scanf("%d",&num);
    int *arr = (int*)malloc(num*sizeof(int));
    printf("Input the Elements\n");
    for(int i = 0; i<num; i++)
        scanf("%d",&arr[i]);
    for(int i = 0;i<num;i++)
    if(isArmstrong(arr[i]))// && > 9
        printf("%d is Armstrong\n",arr[i]);
}