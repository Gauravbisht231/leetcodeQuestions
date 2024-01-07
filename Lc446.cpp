class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
    long long res=0;
    int n= nums.size();
    unordered_map<long long, long long> dp[n+1];
    for(int j=1;j<n; j++){
        for(int i=0; i<j; i++){
            long long commonDiff= (long long)nums[j]- (long long)nums[i];
            int NumElements=0;
            if(dp[i].count(commonDiff)) // if till index 'i' any another index (lesser than i) is associated with same commonDiff, then count them as well
            {
                NumElements = dp[i][commonDiff];
            }
            dp[j][commonDiff]+= NumElements+1;
            res+= NumElements;

        }
    }


    return (int)res;

    }
};