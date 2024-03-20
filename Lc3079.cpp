/*
You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.

Return the sum of encrypted elements.

 

Example 1:

Input: nums = [1,2,3]

Output: 6

Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    int encrypt(int x){
        vector<int> res;
        while(x){
            int last= x%10;
            res.push_back(last);
            x= x/10;
        }
        sort(res.begin(), res.end());
        int n= res.size();
        int maxi= res[n-1];
        int a=0;
        for(int i=0; i<n; i++) res[i]= maxi;
        for(int i=0;i<n; i++) a= a*10 +res[i];
        return a;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        long sum=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            int x= nums[i];
            sum+= encrypt(x);
            }
        return sum;
    }
};