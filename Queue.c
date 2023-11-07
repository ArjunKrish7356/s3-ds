#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue[max];
int front=-1,rear=-1;

void enque(int item){
    if (rear == max-1)
        printf("Queue is full");
    else{
        if(front== -1 && rear == -1){
            front=0;
            queue[++rear]=item;
        }
        else
            queue[++rear]=item;
    }
}
void deque(){
    int item;
    if (rear==-1){
        printf("Queue is empty");
    }
    else{
        item=queue[front++];
        printf(" Item is : %d",item);
    }
}
int main(){
    int choice,item;
    while(5){
        printf("Enter your choice : \n");
        printf(" 1.enque 2.deque 3.exit : \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :{ printf("Enter the element to be enqued : ");
                     scanf("%d",&item);
                     enque(item);
                     break;}
            case 2 : {deque();
                      break;}
            case 3 : exit(0);      
            default: printf("\nInvalid choice! please try again\n");              
        }
    }
}