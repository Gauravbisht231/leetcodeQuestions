/*

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int findMaxLength(vector<int>& nums) {
    int n= nums.size();
    vector<int> pre(n, 0);
    unordered_map<int, int> mp;

    pre[0]= nums[0]==0?-1:1;
    for(int i=1; i<n; i++){
       if(nums[i]==1) pre[i]= pre[i-1] + 1;
       else pre[i]= pre[i-1] -1;
    }
    int maxlen=0;
    for(auto it: pre) cout<<it<<endl;
    mp[0]=-1;
    for(int i=0; i<n; i++){
        int curSum=pre[i];
       if(mp.find(curSum)!= mp.end()) {
        maxlen= max(maxlen, i-mp[curSum] );
       }
       else {
         mp[curSum]= i;   
        }
    }
    return maxlen;
}
};