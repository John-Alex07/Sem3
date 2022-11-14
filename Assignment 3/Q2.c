#include <stdio.h>
#include <stdlib.h>
int *reverse(int *a,int num)
{
    for(int i = 0; i<num/2; i++)
    {
         int t = a[i];
        a[i] = a[num-i-1];
        a[num-i-1] = t; 
    }
    return a;
}
int print_arr(int *a,int num)
{
    for(int i = 0; i < num; i++)
      printf("%d ",a[i]);
}
int main()
{
    int num;
    printf("Enter the number of inputs\n");
    scanf("%d",&num);
    int *arr = (int*)malloc(sizeof(int));
    printf("Input the Elements\n");
    for(int i = 0; i<num;i++)
    {
        scanf("%d",&arr[i]);
        arr = realloc(arr,i+1);
    }
    arr = reverse(arr,num);
    print_arr(arr,num);
    return 0; 
}
