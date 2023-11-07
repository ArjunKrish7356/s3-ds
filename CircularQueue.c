#include<stdio.h>
#include<stdlib.h>
#define max 5
int Cirque[max];
int front=-1,rear=-1;

void enque(int item){
   if(front==-1){
    front=rear=0;
   }
   else{
    if((rear+1)%max!=front){
        rear=(rear+1)%max;
        Cirque[rear]=item;
    }
    else{
        printf("queue is full\n");
    }
   }
}
void deque(){
    int item;
    if(front == -1)
        printf("Queue is empty");
    else{
        item= Cirque[front];
        printf("Item is : %d", item);
        if (front == rear) {

            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % max;
        }
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