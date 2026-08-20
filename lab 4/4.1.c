#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*insertHead(struct Node*head,int value){
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    return newNode;
}

struct Node*insertTail(struct Node*head,int value){
    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL)
        return newNode;

    struct Node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    return head;
}

struct Node*insertAtPosition(struct Node*head,int value,int pos){
    if(pos==1)
        return insertHead(head,value);

    struct Node*newNode=malloc(sizeof(struct Node));
    newNode->data=value;

    struct Node*temp=head;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;

    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}

int main(){
    struct Node*head=NULL;

    head=insertTail(head,10);
    head=insertTail(head,20);
    head=insertTail(head,30);

    head=insertHead(head,5);
    head=insertAtPosition(head,15,3);
    head=insertTail(head,40);

    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}