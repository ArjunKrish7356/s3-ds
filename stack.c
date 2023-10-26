//

#include <stdio.h>
int top=0;
int min=1000;     //Code of min-stack
void push( int stack[]){
  int n;
  printf("Enter the number to be pushed : ");
  scanf("%d",&n);
  if(top==10){
    printf("Stack is full");
  }
  else{
    stack[top]=n;
    top=top+1;
    
    if(n<min){    //code of min-stack
        min = n;
    }
  } 
}
void pop(int stack[]){
    if(top<0){
        printf("Stack is empty");
        }
    else{
        printf("%d",stack[top-1]);
        top--;
    }
}
void peek( int stack[]){
    if(top<0){
        printf("Stack is empty");
        }
    else{
        printf("%d",stack[top-1]);
    }
}
void minimum(){           // code of min-stack
    printf("Minimum values is : %d",min);
}



void main(){

 int stack[10],n;
 while(n!=10){

    printf("\n Enter Your Choice : ");
    printf("\n 1.Push 2.Pop 3.Peek 4.Min 5.Exit ");
    scanf("%d",&n);
    if(n==1){
        push(stack);
    }
    else if(n==2){
        pop(stack);
    }
    else if(n==3){
        peek(stack);
    }
    else if(n==4){      // Code of min-stack
        minimum();
    }
    else if(n==5){
        n=10;
    }
    else{
        printf("Incorrect value! Try again");
    }
 }
}