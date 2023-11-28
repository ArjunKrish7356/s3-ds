#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}node;

struct node* Create(int value){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;
    return newnode;
}
void Add_L(int data,struct node** head,struct node** rear){
    struct node* newnode=Create(data);
    if(*head==NULL) {
        *head=newnode;
        *rear=newnode;
    }
    else{
        struct node* current= *head;
        while(current->next!=NULL)
            current=current->next;
        current->next=newnode;
        newnode->prev=current;
        *rear=newnode;
    }
}
void Add_F(int data,struct node** head,struct node** rear){
    struct node* newnode=Create(data);
    if(*head==NULL) {
        *head=newnode;
        *rear=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
        newnode->next->prev=newnode;
    }
}
void DeQ_F(struct node** head){
    printf("Value is : %d", (*head)->data);
    (*head)=((*head)->next);
    (*head)->prev=NULL;
}
void DeQ_L(struct node** rear){
    printf("Value is : %d", (*rear)->data);
    *rear=(*rear)->prev;
    (*rear)->next=NULL;
}
void Push(int value,struct node*** head){
    struct node* newnode= Create(value);
    newnode->next=**head;
    **head=newnode;
}
void Pop(struct node*** head){
    struct node* temp;
    temp=**head;
    printf("%d", temp->data);
    temp=temp->next;
    **head=temp;
}
void rev(struct node** head,struct node** top){
    struct node* current = *head;
    while(current->next!=NULL){
        Push(current->data,&top);
        current=current->next;
    }
    while((*top)->next!=NULL){
        Pop(&top);
        *top=(*top)->next;
    }
}
void display(struct node** head){
    struct node* temp=*head;
    while(temp->next!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d ", temp->data);
}

void main(){
    int n=10;
    int data;
    struct node* head=NULL;
    struct node* rear=NULL;
    struct node* top=NULL;
    while(n!=5){
        printf("Enter your operation--> 1.EnQ_F 2.EnQ_L 3.DeQ_F 4.DeQ_L");
        scanf("%d",&n);
        switch (n)
        {
        case 1 :{
            printf("Enter the value to be added : ");
            scanf("%d", &data);
            Add_F(data, &head, &rear);
                }
            break;
        
        case 2 :{
            printf("Enter the value to be added : ");
            scanf("%d", &data);
            Add_L(data, &head, &rear);
                }
            break;

        case 3 :{
                  DeQ_F(&head);
                }
            break;

        case 4 :{
                  
                  DeQ_L(&rear);
                }
            break;

        case 6 :{
                  display(&head);
                }
            break;
        case 7 :  rev(&head,&top);
            break;

        default:
            printf("Try again ");
            break;
        }
    }
}

