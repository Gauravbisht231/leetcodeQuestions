#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n= temperatures.size();
        vector<int> temp(n, 0);
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            if(st.empty()) st.push({temperatures[i], i});
            else {
                int element= temperatures[i];
                while(!st.empty() and st.top().first<element){
                    temp[st.top().second]= i-st.top().second;
                    st.pop();
                }
            }
            st.push({temperatures[i], i});
        }
    return temp;
    }
};