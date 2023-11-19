//use 2 stacks to implement a sorted push in a stack so that stack is maintained in a sorted order

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
int temp[MAX];
int temptop = -1;
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
void sort()
{
    int item;
    while (top != -1)
    {
        item = pop();
        while (temptop != -1 && temp[temptop] > item)
            push(temp[temptop--]);
        temp[++temptop] = item;
    }
    while (temptop != -1)
        push(temp[temptop--]);
}
void main()
{
    int item, choice;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Sort\n");
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
            sort();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

