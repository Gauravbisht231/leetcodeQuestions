/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0 or nums[i] > n)
                nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++)
        {
            int ind = abs(nums[i]);
            if (ind > n)
                continue;
            nums[ind - 1] <= -1 ? (nums[ind - 1] = nums[ind - 1]) : (nums[ind - 1] = -nums[ind - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
                return i + 1;
        }
        return n + 1;
    }
};

// brute:

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n= nums.size();
//         set<int> st;
//         for(auto it: nums ){
//             st.insert(it);
//         }
//         int i=1;
//         for(i; i<=n; i++){
//             if(st.find(i)== st.end()) return i;
//         }
//         return -1;
//     }
// };