//JOHN ALEXANDER E 20011896
#include <stdio.h>
#include <string.h>
typedef struct Stack
{
    int top;
    char exp[100];
    int arr[100];
}Stack;
Stack exp_ini(Stack *s)
{
    s->top = -1;
    printf("Enter the expression\n");
    fgets(s->exp,100,stdin);
    int l = strlen(s->exp);
    int c = 0,i=0;
    for(int i = 0;i<=l;i++)
        if(s->exp[i] != 32)
         s->exp[c++] = s->exp[i];
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
int push(char ch, Stack *s)
{
       s->arr[++s->top] = ch;
}
char pop(Stack *s)
{
    if(!isEmpty(s))
    return s->arr[s->top--];
}
int Precedence(char ch)
{
    static int p = 3;
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return p++;
        default:
        return -1;
    }
}

char *INtoPO(Stack *s)
{
    char ex[100];
    int i = 0,c = -1;
  while(s->exp[i] != '\0')
  {
      if(isalpha(s->exp[i]))
        {
            ++c;
            ex[c] = s->exp[i];
        }
      else
        if(s->exp[i] == '(')
        push(s->exp[i], s);
      else
        if(s->exp[i] == ')')
        {
            while(!isEmpty(s) && s->arr[s->top] != '(')
            {
                c++;
                ex[c] = pop(s);
            }
            pop(s);
        }
      else
        {
            
            while( !isEmpty(s) && Precedence(s->arr[s->top]) >= (Precedence(s->exp[i]) ))
           {
              c++;
              ex[c] = pop(s);
           }
          push(s->exp[i], s);
        }
        i++;
   }
    while(!isEmpty(s))
    {
        c++;
        ex[c] = pop(s);
    }
    ex[++c] = '\0';
    printf("Infix : %s\n",s->exp);
    printf("Postfix : %s",ex);
}
int main()
{
    Stack s;
    exp_ini(&s);
    INtoPO(&s);
}