/*
                                                            Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
       vector<int> dp(n, 1), path(n,0);
       for(int i=0; i<n; i++) path[i]=i;
       int maxlen=0;
       int maxlenInd=0;
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<i; j++){
               if(nums[i]%nums[j]==0){
                   if(dp[j] >= dp[i]) { // when equal
                       dp[i]= dp[j]+1;
                       path[i]=j;
                   }
                   
               }
               if(maxlen < dp[i]){
                       maxlen= dp[i];
                        maxlenInd= i;
                   }
           }
       }
    vector<int> lis;
       while(maxlenInd!= path[maxlenInd]){
           lis.push_back(nums[maxlenInd]);
           maxlenInd= path[maxlenInd];
       }
       lis.push_back(nums[maxlenInd]);
       reverse(lis.begin(), lis.end());
       return lis;
    }
};