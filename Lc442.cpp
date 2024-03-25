/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> res;
       int n= nums.size();

       for(int i=0; i<n; i++){
      int ind= abs(nums[i]); // kya pata isko kabhi mark kar dein hum pehle hi
      ind-= 1;
      if(nums[ind]<0) res.push_back(ind+1);
      else nums[ind]= -nums[ind];
       } 
       return res;
    }
};
