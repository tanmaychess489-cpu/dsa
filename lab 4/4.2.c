#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*deleteHead(struct Node*head){
    if(head==NULL)
        return NULL;

    struct Node*temp=head;
    head=head->next;
    free(temp);

    return head;
}

struct Node*deleteTail(struct Node*head){
    if(head==NULL)
        return NULL;

    if(head->next==NULL){
        free(head);
        return NULL;
    }

    struct Node*temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;

    free(temp->next);
    temp->next=NULL;

    return head;
}

struct Node*deleteAtPosition(struct Node*head,int pos){
    if(pos==1)
        return deleteHead(head);

    if(head==NULL)
        return NULL;

    struct Node*temp=head;

    for(int i=1;i<pos-1;i++)
        temp=temp->next;

    struct Node*deleteNode=temp->next;
    temp->next=deleteNode->next;
    free(deleteNode);

    return head;
}

int main(){
    struct Node*n1=malloc(sizeof(struct Node));
    struct Node*n2=malloc(sizeof(struct Node));
    struct Node*n3=malloc(sizeof(struct Node));
    struct Node*n4=malloc(sizeof(struct Node));
    struct Node*n5=malloc(sizeof(struct Node));

    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;
    n5->data=50;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;


    struct Node*head=n1;

    head=deleteHead(head);
    head=deleteAtPosition(head,2);
    head=deleteTail(head);

    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}