/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> res(n, 0), pre(n, 1), suf(n, 1);
        pre[0]= nums[0];
        suf[n-1]= nums[n-1];
        for(int i=1; i<n; i++){
            pre[i]= pre[i-1]*nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suf[i]= suf[i+1]*nums[i];
        }
        for(int i=0; i<n; i++){
            if(i==0){
                res[i]=suf[i+1];
            }else if(i==n-1){
                res[i]= pre[i-1];
            }else {
                res[i]= pre[i-1]*suf[i+1];
            }
        }
        

        return res;
    }
};