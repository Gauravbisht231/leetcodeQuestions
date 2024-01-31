#include<bits/stdc++.h>
using namespace std;
class Solution {
int n;
int helper(int ind, vector<int> &coins, int amount,  vector<vector<int>> &memo){
    if(amount==0) return 0;
    if(ind>=n) return 1e9;
    if(memo[ind][amount]!=-1) return memo[ind][amount];
    int take= 1e9;
    if(coins[ind]<=amount) take= 1 + helper(ind, coins, amount- coins[ind], memo);
    int nottake= 0 +  helper(ind+1, coins, amount, memo);
    return memo[ind][amount]= min(take, nottake);

}
public:
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
//                                          Memoised code: 
        // int total= 0;
        // vector<vector<int>> memo(n+1, vector<int>(amount+1, -1));
        // total= helper(0, coins, amount,memo);
        // return total==1e9?-1:total;
//                                          Tabulated code:
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, 1e9));
// Convert                                  Space optimised :
        vector<int> next(amount+1, 1e9);
        for(int i=0; i<n; i++){
            next[0]=0;
        }
        for(int ind=n-1;ind>=0; ind--){
            vector<int> cur(amount+1, 0);
            for(int amt=1; amt<=amount; amt++){
                int take= 1e9;
                if(coins[ind]<=amt) take= 1 + cur[amt- coins[ind]];
                int nottake= 0 + next[amt];
                cur[amt]= min(take, nottake);
            }
            next= cur;
        }
return next[amount]==1e9?-1:next[amount];
    }
};