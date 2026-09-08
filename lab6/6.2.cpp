#include<iostream>
using namespace std;
class Stack{
    int top=-1;
    int arr[100];
    public:
    void push(int val){
        if(top==99){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int gettop(){
        if(top==-1){
            cout<<"Stack is empty"<<" ";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        if(top==-1)
        return true;
        else
        return false;

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
    
