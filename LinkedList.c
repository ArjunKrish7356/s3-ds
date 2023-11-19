#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* Create(int value){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
} 

void insert_E(int value, struct node **head){
    struct node* newnode = Create(value);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}
void insert_F(int value,struct node **head){
    struct node *newnode = Create(value);
    if(*head == NULL){
        *head=newnode;
    }
    else{
        newnode->next=*head;
        *head=newnode;
    }
}
void insert_any(int value,int item,struct node **head){
    struct node *newnode = Create(value);
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node* ptr = *head;
        while(ptr->data != item && ptr->next!=NULL){
            ptr=ptr->next;
        }
        if(ptr->next == NULL)
            printf("Item not found");
        else{
            newnode->next=ptr->next;
            ptr->next= newnode;
        }
    }
}

int main(){
    int n = 10,m;
    struct node* head = NULL;
    struct node* current;
    while(n != 5){
        printf("Enter your operation: 1.Insert_E 2.show all 3.Insert_F ");
        scanf("%d", &n);
        if(n == 1){
            printf("Enter the value: ");
            scanf("%d", &m);
            insert_E(m, &head);
        }
        else if(n == 2){
            current = head;
            while(current != NULL){
                printf("%d ", current->data);
                current = current->next;
            }
            printf("\n");
        }
        else if( n== 3){
            printf("Enter the value: ");
            scanf("%d", &m);
            insert_F(m, &head);
        }
        else if( n==4){
            int item;
            printf("Enter the value: ");
            scanf("%d", &m);
            printf("Enter the item :");
            scanf("%d",&item);
            insert_any(m,item, &head);
        }
    }
    return 0;
}