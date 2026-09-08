#include<iostream>
using namespace std;
struct ListNode{
    
    int val;
    ListNode* next;
};
class Stack{
    ListNode* top=nullptr;
    public:
    void push(int val){
        ListNode* newNode=new ListNode();
        newNode->val=val;
        newNode->next=top;
        top=newNode;
    }   
    void pop(){
        if(top==nullptr){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        ListNode* temp=top;
        top=top->next;
        delete temp;
    }
    int gettop(){
        if(top==nullptr){
            cout<<"Stack is empty"<<" ";
            return -1;
        }
        return top->val;
    }
    bool isEmpty(){
        return top==nullptr;
    }
    

};
int main(){
    Stack s;
    s.push(5);
    s.push(10);
    cout<<s.gettop()<<endl;
    s.pop();
    cout<<s.gettop()<<endl;
    s.pop();
    cout<<s.gettop()<<endl;
    cout<<s.isEmpty()<<endl;
    s.push(50);
    cout<<s.gettop()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    s.pop();
    return 0;

}