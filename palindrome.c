#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node * next;
    struct node * prev;
}node;

struct node* Create(char value){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=value;
    return newnode;
}
void addtolist(char data,struct node** head){
    struct node* newnode=Create(data);
    if(*head==NULL) {
        *head=newnode;
    }
    else{
        struct node* current= *head;
        while(current->next!=NULL)
            current=current->next;
        current->next=newnode;
        newnode->prev=current;
    }
    
}
int palindrome(struct node** head){
    struct node* current= *head;
    struct node* first= *head;
    struct node* last= *head;

    while(current->next!=NULL)
        current=current->next;
    last=current;
    while(first!=last){
        if(first->data!=last->data){
            printf("Not a Palindrome");
            return 0;
        }
        else{
            first=first->next;
            last=last->prev;
        }
    }
    
    printf("Palindrome");
    return 0;
}
int main(){
    char str[30];
    int i=0;
    struct node* head= NULL;
    printf("Enter your Word : ");
    scanf("%[^\n]s",str);
    while(str[i]!='\0'){
        addtolist(str[i], &head);
        i++;
    }
    palindrome(&head);
}