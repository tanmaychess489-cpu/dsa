#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
};
ListNode* reverseList(ListNode* head){
    ListNode* prev=nullptr;
    ListNode* curr=head;
    ListNode*next=head->next;
    while(curr!=nullptr){
        curr->next=prev;
        if(next!=nullptr){
            prev=curr;
            curr=next;
            next=next->next;
        }
        else{
            prev=curr;
            curr=next;
        }
    }
    return prev;
}
int main() {
    cout<<"Enter the number of nodes:";
    int n;
    cin>>n;
    
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
            break;
        }
    }
    ListNode* head=n1;
    head=reverseList(head);
    ListNode* temp=head;
    while(temp->next!=head){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<temp->val<<" ";
    return 0;

}
