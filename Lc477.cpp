/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Example 2:

Input: nums = [4,14,4]
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int diff=0;
        int n= nums.size();
    for(int i=0; i<32; i++){
        int countRightOnes=0;
            for(int ind=0; ind<n; ind++){
                    if(nums[ind]&1==1) countRightOnes++;
                    nums[ind]= nums[ind]>>1; 
            }
            diff+= (n-countRightOnes)*countRightOnes;
    }



        return diff;
    }
};



                                    // O(N2) approach
// class Solution {
// private:
// map<pair<int, int> ,int> dp;
// int check(int a, int b){
//     int c= a^b;
//     int res=0;
//     while(c){
//         if(c&1==1) res++;
//         c=c>>1;
//     }
//     dp[{a, b}]=res;
//     return res;
// }
// public:
//     int totalHammingDistance(vector<int>& nums) {
//         int diff=0;
//         int n= nums.size();
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int a= nums[i], b= nums[j];
//                 if(dp.find({a,b})!= dp.end()) diff= dp[{a, b}];
//                 else diff+= check(a, b);
//             }
//         }
//         return diff;
//     }
// };

