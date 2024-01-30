#include<bits/stdc++.h>
using namespace std;
class Solution {
set<string> op= {"*", "/", "-", "+"};
public:
    int evalRPN(vector<string>& tokens) {
        int n= tokens.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(op.find(tokens[i])!= op.end()){
                int first=st.top();
                st.pop();
                int second= st.top();
                st.pop();
                if(tokens[i]=="+") st.push(first + second);
                if(tokens[i]=="-") st.push(second - first);
                if(tokens[i]=="*") st.push(first * second);
                if(tokens[i]=="/") st.push(second / first);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};