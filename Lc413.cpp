class Solution {

public:
    int numberOfArithmeticSlices(vector<int>& nums) {
    int res=0;
    int i=2;
    int n= nums.size();
    vector<int> dp(n, 0);
    for(i; i<n; i++){
        int diff= nums[i]- nums[i-1];
        if(diff== (nums[i-1]- nums[i-2])) dp[i]= dp[i-1]+1;
        else continue;   
    }
    res= accumulate(dp.begin(), dp.end(),0);

    return res;


    }
};