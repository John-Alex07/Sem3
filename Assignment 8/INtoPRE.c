//JOHN ALEXANDER E 20011896
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct Stack
{
    int arr[100];
    char exp[100];
    int top;
}Stack;
Stack s;
void initialize()
{
    printf("JOHN ALEXANDER E 20011896\n");
    s.top = -1;
    printf("Enter an expression\n");
    scanf("%s",s.exp);
}
int push(char ch)
{
  s.arr[++s.top] = ch;
}
int pop()
{
    return s.arr[s.top--];
}
int prec(char ch)
{
    static int k = 3;
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return k++;
        default :
        return -1;
    }
}
int isEmpty()
{
    return s.top == -1;
}
char* rev_exp()
{
   char *ex = strrev(s.exp);
   for(int i = 0;ex[i]!='\0';i++)
   if(ex[i] == ')')
   ex[i] = '(';
   else
   if(ex[i] == '(')
   ex[i] = ')';
   return ex;   
}
char *prefix(char *ex)
{
    int c = 0;
   for(int i = 0;ex[i]!='\0';i++)
   {
     if(isalpha(ex[i]) || isdigit(ex[i]))
     ex[c++] = ex[i];
     else
     if(ex[i] == '(')
       push(ex[i]);
      else
      if(ex[i] == ')')
        { 
            while(!isEmpty() && s.arr[s.top] != '(')
               ex[c++] = pop();
          pop();
        }
       else
          {
            while(!isEmpty() && prec(ex[i]) < prec(s.arr[s.top]))
                  ex[c++] = pop();
             push(ex[i]);
          }
    }
    while(!isEmpty())
    ex[c++] = pop();
    ex = strrev(ex);
    printf("PREFIX : %s",ex);
    return ex;
}
int calc(int op1, int op2, char ch)
{
    switch(ch)
    {
        case '+':
        return push(op1+op2);
        case '-':
        return push(op1-op2);
        case '*':
        return push(op1*op2);
        case '/':
        return push(op1/op2);
        case '^':
        return push(pow(op1,op2));
    }
}
int evaluate(char *ex)
{
    int l = strlen(ex);
    for(int i = l-1;i>=0;i--)
      if(isdigit(ex[i]))
      push(ex[i] - '0');
      else
         {
             int op1 = pop();
             int op2 = pop();
             calc(op1,op2,ex[i]);
         }
    printf("\nRESULT : %d",pop());
}
int main()
{
    initialize();
    char *ex = rev_exp();
    ex = prefix(ex);
    evaluate(ex);
}