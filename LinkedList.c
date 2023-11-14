#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

struct *node Create(int value){
    struct node newnode = malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
} 

void addnode(int value,struct node **head){
    struct node* newnode=Create(value);
    struct node* current=*head;
    while((current->next)!=NULL)
        current=current->next;
    current->next=newnoed;
}

