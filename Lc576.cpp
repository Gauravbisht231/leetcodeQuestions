#include<bits/stdc++.h>
using namespace std;
class Solution {
    // recursive-----> O(50^4) give tle
    vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
    int mod=1e9+7;
    int helper(int n, int m, int moves, int ro, int col, vector<vector<vector<int>>> &memo) {
        if (moves < 0)
            return 0;
        if ((ro == n or ro < 0 or col == m or col < 0) and moves >= 0)
            return 1;
        if(memo[ro][col][moves]!=-1) return memo[ro][col][moves];
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int newRo = ro + dr[i];
            int newCol = col + dc[i];
            res = (res + helper(n, m, moves - 1, newRo, newCol, memo))%mod;
        }
        return memo[ro][col][moves]= res;
    }

public:
    int findPaths(int n, int m, int moves, int r, int c) {
        int res = 0;
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>> (m+1, vector<int> (moves+1, -1)));

        res = helper(n, m, moves, r, c, memo);
        return res;
    }
};