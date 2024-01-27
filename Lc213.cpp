#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
int helper(int ind, vector<int> &nums, int n, vector<int>&memo){
    if(ind>=n) return 0;
    if(memo[ind]!=-1) return  memo[ind];
    int take=0, nottake=0;
    take= nums[ind] + helper(ind+2, nums, n, memo);
    nottake= 0 + helper(ind+1, nums,n, memo);
    return memo[ind]= max(take, nottake);
}
int tab(vector<int> &arr, int n)
{
    vector<int> dp(n+1, 0);
    dp[n-1]= arr[n-1];
for(int ind=n-2; ind>=0; ind--){
    int take=0, nottake=0;
    take= arr[ind] + dp[ind+2];
    nottake= 0 + dp[ind+1];
    dp[ind]= max(take, nottake);
    }
    return dp[0];
}
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)  return nums[0];
                    //  memoised calls
        // vector<int> mem1(n+1, -1); 
        // vector<int> mem2(n+1, -1); 
        // int one= helper(0, nums, n-1, mem1);
        // int two= helper(1, nums, n, mem2);
        //   return max(one, two);

        //                  Tabulated 
        vector<int> arr1, arr2;
       for(int i=0; i<n; i++){
           if(i!=0) arr2.push_back(nums[i]);
           if(i!=n-1) arr1.push_back(nums[i]);
       }
       return max(tab(arr1, n-1), tab(arr2, n-1));

    }
};