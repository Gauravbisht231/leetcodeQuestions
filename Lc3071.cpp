/*
You are given a 0-indexed n x n grid where n is odd, and grid[r][c] is 0, 1, or 2.

We say that a cell belongs to the Letter Y if it belongs to one of the following:

The diagonal starting at the top-left cell and ending at the center cell of the grid.
The diagonal starting at the top-right cell and ending at the center cell of the grid.
The vertical line starting at the center cell and ending at the bottom border of the grid.
The Letter Y is written on the grid if and only if:

All values at cells belonging to the Y are equal.
All values at cells not belonging to the Y are equal.
The values at cells belonging to the Y are different from the values at cells not belonging to the Y.
Return the minimum number of operations needed to write the letter Y on the grid given that in one operation you can change the value at any cell to 0, 1, or 2.

 

Example 1:


Input: grid = [[1,2,2],[1,1,0],[0,1,0]]
Output: 3
Explanation: We can write Y on the grid by applying the changes highlighted in blue in the image above. After the operations, all cells that belong to Y, denoted in bold, have the same value of 1 while those that do not belong to Y are equal to 0.
It can be shown that 3 is the minimum number of operations needed to write Y on the grid.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    // copy pe dry run kiya ;-)
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int mini=1e9;
        int n= grid.size();
        vector<int> y(3, 0), z(3, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    if((i<=n/2 and i==j) or (i<=n/2 and (i+j)==n-1) or (i>n/2 and j==n/2)){
                        y[grid[i][j]]++;
                    }else{
                        z[grid[i][j]]++;
                    }
            }
        }
        int totalY=accumulate(y.begin(), y.end(), 0);
        int totalZ=accumulate(z.begin(), z.end(), 0);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==j) continue;
                else {
                    mini= min(mini, n*n -y[i] - z[j]);
                }
            }
        }


        return mini;
    }
};