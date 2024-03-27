/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0;
        int i=0, j=0, n= nums.size();
        if(k==0) return 0;
        int prod= 1;
        while(j<n){
            prod= prod*nums[j];
            while(prod>=k and i<=j){
                prod/=nums[i];
                i++;
            }
            res+= j-i+1;
            j++;
        }

        return res;
    }
};

/* 
                            // Brute force  
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            int prod= 1;
            for(int j=i; j<n; j++){
              prod*= nums[j];
              if(prod<k) res++;
              else break;
            }
        }

        return res;
    }
};
*/
