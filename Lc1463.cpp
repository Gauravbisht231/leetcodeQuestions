/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
// vector<int> dc1= {-1, 0, 1}, dc2= {-1, 0, 1};
int n, m;
int helper(int ro, int col1, int col2,vector<vector<int>>& grid){
    if(col1>=m or col1<0 or col2>=m or col2<0) return 0;
    if(ro==n-1) {
        if(col1==col2) return grid[ro][col1];
        else return grid[ro][col2] + grid[ro][col1];
    }

    int cherries=0;
    for(int c1=-1; c1<=1; c1++)
    {
        for(int c2=-1; c2<=1; c2++){
            int cost=0;
            int newcol1= c1 + col1;
            int newcol2= c2 + col2;
            if(col1== col2) cost+= grid[ro][col1] + helper(ro+1, newcol1, newcol2, grid);
            else cost+= grid[ro][col1] + grid[ro][col2] + helper(ro+1, newcol1, newcol2,grid);
            cherries= max(cherries, cost);
        }
    }
    return cherries;
}
public:
int cherryPickup(vector<vector<int>>& grid) {
int cherries=0;
n= grid.size(), m= grid[0].size();
                                //                    Recursive code:
// cherries= helper(0, 0, m-1, grid);
// return cherries;
//                                                       Tabulated code:
vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1, vector<int>(m+1, 0)));
for(int col1=0; col1<m; col1++){
    for(int col2=0; col2<m; col2++){
        if(col2==col1) dp[n-1][col1][col2]= grid[n-1][col2];
        else dp[n-1][col1][col2]= grid[n-1][col1] + grid[n-1][col2];
    }}
for(int ro= n-2; ro>=0; ro--){
    for(int col1=0; col1<m; col1++){
        for(int col2=0; col2<m; col2++){
            int cherries=0;
             for(int c1=-1; c1<=1; c1++){
             for(int c2=-1; c2<=1; c2++){
            int newcol1= c1 + col1;
            int newcol2= c2 + col2;
            int cost=0;
            if(newcol2>=0 and newcol2<m and newcol1>=0 and newcol1<m){
            if(col1== col2) cost+= grid[ro][col1] + dp[ro+1][newcol1][newcol2];
            else cost+= grid[ro][col1] + grid[ro][col2] + dp[ro+1][newcol1][newcol2];
            }else cost=0;
            cherries= max(cherries, cost);
        }
    }
    dp[ro][col1][col2]= cherries;
        }
    }
}
return dp[0][0][m-1];

    }
};