#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Input the binary number\n");
    char *bn = (char*)malloc(100*(sizeof(char)));
    scanf("%s",bn);
    int k = 0,c = 0;
    while(bn[k]!=NULL)
      {
          if(bn[k]=='1')
               c++;
          k++;
      }
    for(int i = 0; i < k; i++)
    {
       if(i < c)
         bn[i] = '1';
         else
         bn[i] = '0';
    }
    printf("%s",bn);
}