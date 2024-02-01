#include<bits/stdc++.h>
using namespace std;
class Solution {
int res=0;
int dp[1001][1001];
// recursion + Memoisation function:
int helper(int i, int j, vector<int>& s, vector<int>& t, int n, int m)
{
    if(i>=n or j>=m) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    int same=0;
    if(s[i]==t[j]) same= 1 + helper(i+1,j+1,s,t,n,m);
    helper(i,j+1,s,t,n,m);
    helper(i+1,j,s,t,n,m);
    res= max(res, same);
    return dp[i][j]= same;
}
public:
    int findLength(vector<int>& s, vector<int>& t) {
        int n= s.size();
        int m= t.size();
//                               Memoised code:
        // memset(dp, -1, sizeof(dp));
        // helper(0, 0, nums1, nums2, n, m);
        // return res;
//                                Tabulated code:
        // memset(dp, 0, sizeof(dp));
//                                 Space Optimised code:
        vector<int> next(m+1, 0);
        for(int i=n-1; i>=0; i--){
            vector<int> cur(m+1, 0);
            for(int j=0; j<m;j++){
                int same=0;
                if(s[i]==t[j]) same= 1 + next[j+1];
                // helper(i,j+1,s,t,n,m);
                // helper(i+1,j,s,t,n,m);
                res= max(res, same);
                cur[j]= same;
            }
            next= cur;
        }
        return res;
    }

};