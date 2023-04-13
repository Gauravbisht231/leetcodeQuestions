class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0, j=0;
        int n= pushed.size();
        for(int i=0; i<n;i++){
            st.push(pushed[i]); // push the element as soon as you enter the loop everytime
            while(!st.empty() and st.top()==popped[j]){
                st.pop(); j++;
            }
        }
        return st.empty();
    }
};
