#include<iostream>
#include<string>
#include<stack>
using namespace std;
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxlength=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(i);

        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                maxlength=max(maxlength,i-st.top());
                

            }
        }
    }
    return maxlength;
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    int result=longestValidParentheses(s);
    cout<<result<<endl;  
    return 0;
}