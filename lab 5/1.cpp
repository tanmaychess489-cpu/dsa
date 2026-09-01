#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
};
    ListNode* deletion(ListNode* head,int pos) {
        if(head==NULL){
            return NULL;
        }
        if(pos==1){
        
        ListNode* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=head->next;
        delete head;
        head=temp->next;
        return head;
    }
    if(pos>1){
        ListNode* temp=head;
        int count=1;
        ListNode* prev=nullptr;
        while(count<pos){
            prev=temp;
            temp=temp->next;
            count++;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
        
}
ListNode* insertion(ListNode* head,int pos,int val){
    ListNode* newnode=new ListNode();
    newnode->val=val;
    if(pos==1){
        ListNode* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        return head;
    }
    if(pos>1){
        ListNode* temp=head;
        ListNode* newnode=new ListNode();
        newnode->val=val;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;

    }
}
int main() {
    cout<<"Enter the number of nodes:";
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"List is empty so no deletion";
        return 0;
    }
    ListNode* n1=new ListNode();
    ListNode* tmp=n1;
    for(int i=1;i<=n;i++){
        cout<<"Enter the value of node "<<i<<":";
        cin>>tmp->val;
        if(i!=n){
            tmp->next=new ListNode();
            tmp=tmp->next;
        }
        else{
            tmp->next=n1;
        }
    }
    ListNode* head=n1;
    int pos;
    cout<<"Enter the position of node to be deleted:";
    cin>>pos;
    head =deletion(head,pos);
    int pos1,val;
    cout<<"Enter position of node to be inserted:";
    cin>>pos1;
    cout<<"Enter value of node to be inserted:";
    cin>>val;
    head=insertion(head,pos1,val);
    ListNode* temp=head;
    while(temp->next!=head){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<temp->val<<" ";
    return 0;

}