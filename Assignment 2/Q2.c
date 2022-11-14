#include<stdio.h>
int Palin(int num)
{
    int rev=0,rem=0;
    while(num>0) {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    return rev;
}
int main()
{
    printf("JOHN ALEXANDER E 20011896\n");
    int i,n,rev=0;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n],arr2[n];
    printf("Input the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);     
    }
    printf("Palindromes are :");
    for(i=0;i<n;i++)
    {
        rev=Palin(arr[i]);
        if(rev==arr[i]) 
            if(arr[i]>10)
                printf("%d ",arr[i]);
     
    }
}