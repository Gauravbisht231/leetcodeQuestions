#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int helper(int ind, int k, vector<int> &nums, int n, vector<int> &memo)
    {
        if (ind >= n)
            return 0;
        if (memo[ind] != -1)
            return memo[ind];
        int maxsum = 0;
        int len = 0;
        int maxi = -1e9;
        for (int cut = ind; cut < min(n, ind + k); cut++)
        {
            len++;
            maxi = max(maxi, nums[cut]);
            maxsum = max(maxsum, len * maxi + helper(cut + 1, k, nums, n, memo));
        }
        return memo[ind] = maxsum;
    }

public:
    int maxSumAfterPartitioning(vector<int> &nums, int k)
    {
        int maxi = 0;
        int n = nums.size();

        //                      recurion + Memoised code:
        //    vector<int> memo(n+1, -1);
        //    maxi= helper(0,k, nums, n, memo);
        //    return maxi;

        //                              Tabulated code:
        vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            int maxsum = 0;
            int len = 0;
            int maxi = -1e9;
            for (int cut = ind; cut < min(n, ind + k); cut++)
            {
                len++;
                maxi = max(maxi, nums[cut]);
                maxsum = max(maxsum, len * maxi + dp[cut + 1]);
            }
            dp[ind] = maxsum;
        }
        return dp[0];
    }
};