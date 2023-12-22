class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        //  num[1]< num[3]<num[2]
    //  O(N) approach ---- stack
    int x=54;
    int num3= INT_MIN;
    stack<int> st;

    for(int i= n-1; i>=0; i--){
        if(nums[i]< num3) return true;

        while(!st.empty() and nums[i]> st.top()){
             num3= st.top();
             st.pop();
        }
        st.push(nums[i]);

    }
      return false;
    }
};
