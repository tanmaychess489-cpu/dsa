#include<iostream>
#include<string>
#include<stack>
using namespace std;
int precedence(char c){
    if(c=='^'){
        return 4;
    }
    else if(c=='%'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
int main(){
    string infix;
    cout<<"Enter an infix expression:";
    cin>>infix;
    stack<char> st;
    string postfix="";
    for(int i=0;i<infix.length();i++){
        char c=infix[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            postfix+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){
                postfix+=st.top();
                st.pop();
            }
                st.pop();
            
        }
        else{
            while(!st.empty()&&precedence(st.top())>=precedence(c)){
                postfix+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    cout<<"Postfix expression:"<<postfix<<endl;
    return 0;
}