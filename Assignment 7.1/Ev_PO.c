//JOHN ALEXANDER E 20011896
#include <stdio.h>
#include <math.h>
typedef struct Stack
{
    int top;
    int arr[100];
    char exp[100];
}Stack;
Stack s;
int stack_ini()
{
    s.top = -1;
    printf("Enter the postfix expression\n");
    scanf("%s",s.exp);
    //while(s.exp[i] != '\0')
}
int push(char ch)
{
  s.arr[++s.top] = ch; 
}
int pop()
{
    return s.arr[s.top--];
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
int res()
{
    int i = 0;
    while(s.exp[i]!='\0')
    {
      if(isdigit(s.exp[i]))
      push(s.exp[i] - '0');
      else
           {
               int op2 = pop();
               int op1 = pop(); 
             calc(op1,op2,s.exp[i]);
           }
      i++;
    }
    printf("%d",pop());
}
int main()
{
  stack_ini();
  res();
}