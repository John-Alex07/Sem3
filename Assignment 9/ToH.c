//JOHN ALEXANDER E 20011896
#include <stdio.h>
int TofH(int n,int src, int aux, int des)
{
  if(n == 1)
  {
     printf("\nMOVE a disk from %d to %d",src,des);
     return 0;
  }
  TofH(n-1,src,des,aux);
  printf("\nMOVE a disk from %d to %d",src,des);
  TofH(n-1,aux,src,des);
}
int main()
{
    printf("JOHN ALEXANDER E 20011896\n");
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    TofH(n,1,2,3);
}
