/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// not so intuitive solution, but works fine: did took help from CSWM
int numSubarraysWithSum(vector<int>& nums, int k) {
    int res=0;
    int n= nums.size();
    int i=0, j=0;
    int sum=0;
    int preZero=0;
    while(j<n){
        sum+= nums[j];
        while(i<j and (sum>k or nums[i]==0)){
            if(nums[i]==0) preZero++;
            else preZero=0;
            sum-= nums[i];
            i++;
        }
        if(sum==k) res+= preZero +1;
        j++;
    }
    return res;
    
    }
};

// subarry sum k similar approach: Intuitive one
/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int res=0;
        int n= nums.size();
        vector<int> pre(n, 0);
        pre[0]=nums[0];
        for(int i=1; i<n; i++)pre[i]= pre[i-1] + nums[i];

        unordered_map<int, int> mp;
        mp[0]++;
        for(int i=0; i<n; i++){
            int totalSum= pre[i];
            int diff= totalSum-k;
            if(mp.find(diff)!= mp.end()){
                res+= mp[diff];
            }
            mp[totalSum]++;
        }
return res;

    }
};
*/