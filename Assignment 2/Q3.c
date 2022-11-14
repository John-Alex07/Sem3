#include<stdio.h>
#include<math.h>

int Prime(int num)
{
int flag=0;
for(int i=2;i<=sqrt(num);i++) 
{
      if(num%i == 0) 
      {  
          flag = 1; 
           break; 
      }
}
   if(flag == 0 && num!=1 && num!=0)
      printf("%d is a prime number\n", num);
}
int main()
{
    printf("JOHN ALEXANDER E 20011896\n");
    int i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    printf("Input the elements\n");
    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
       Prime(arr[i]);
}