//c program to do postfix evaluation using stack
#include<stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
int main()
{
    char postfix[100];
    int i=0,op1,op2,res;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
            push(postfix[i]-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(postfix[i])
            {
                case '+':res=op1+op2;
                         break;
                case '-':res=op1-op2;
                         break;
                case '*':res=op1*op2;
                         break;
                case '/':res=op1/op2;
                         break;
                case '%':res=op1%op2;
                         break;
                case '^':res=op1^op2;
                         break;
            }
            push(res);
        }
        i++;
    }
    printf("Result=%d\n",pop());
    return 0;
}


