//find the minimum value inside a stack using another stack

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
int minstack[MAX];
int mintop = -1;

void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    if (mintop == -1 || item < minstack[mintop])
        minstack[++mintop] = item;
    else
        minstack[++mintop] = minstack[mintop - 1];
}
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    mintop--;
    return stack[top--];
}
int min()
{
    if (mintop == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return minstack[mintop];
}
void main()
{
    int item, choice;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Min\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item = pop();
            if (item != -1)
                printf("The popped element is %d\n", item);
            break;
        case 3:
            item = min();
            if (item != -1)
                printf("The minimum element is %d\n", item);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
} 