//infix to postfix using stack
#include<stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char symbol)
{
    switch(symbol)
    {
        case '^':return 3;
        case '*':
        case '/':
        case '%':return 2;
        case '+':
        case '-':return 1;
        default:return 0;
    }
}
int main()
{
    char infix[100],postfix[100],item,x;
    int i=0,j=0;
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        item=infix[i];
        if(item=='(')
            push(item);
        else if(isalnum(item))
            postfix[j++]=item;
        else if(item==')')
        {
            while((x=pop())!='(')
                postfix[j++]=x;
        }
        else
        {
            while(precedence(stack[top])>=precedence(item))
                postfix[j++]=pop();
            push(item);
        }
        i++;
    }
    while(top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("Postfix expression is %s\n",postfix);
    return 0;
}

