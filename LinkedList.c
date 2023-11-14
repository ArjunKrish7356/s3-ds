#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node* Create(int value){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
} 

void addnode(int value,struct node **head){
    struct node* newnode=Create(value);
    struct node* current=head;
    while((current->next)!=NULL)
        current=current->next;
    current->next=newnode;
}

void main(){
   int n,*head,*current;
   while(n!=5){
     printf("Enter you operation: ");
     scanf("%d",&n);
     if(n==1){
        addnode(5,&head);
     }
     else if (n==2){
        current=head;
        while((current->next)!=NULL){
            printf("%d",current->data);
            current=current->next;
        }
     }
   }
}


