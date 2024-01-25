#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// Memoisation Fucntion
int helper(int i, int j, string &s, string &t, int n, int m,vector<vector<int>>&memo){
    if(i>=n or j>=m) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
if(s[i]==t[j]) return memo[i][j]= 1 + helper(i+1, j+1, s, t, n,m, memo);
    else {
        return memo[i][j]= max(helper(i+1, j, s, t, n, m, memo),helper(i, j+1, s, t, n, m, memo));
    }
}

int longestCommonSubsequence(string s, string t) {
int n= s.size();
int m= t.size();
                                            //  memoistion funciton call

//  vector<vector<int>> memo(n+1, vector<int> (m+1, -1));
//  return helper(0, 0, s,t,n,m, memo);

                                                    // Tabulation code
vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
for(int i=n-1; i>=0; i--){
    for(int j=m-1; j>=0; j--){
        if(s[i]==t[j])  dp[i][j]= 1 + dp[i+1][j+1];
    else {
         dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
    }
}
    }
return dp[0][0];
}
};
