// //                                RECURSIVE SOLUTION
// class Solution {
// private:
// int helper(vector<vector<int>>& grid, int i, int j, int n, int m){
// if(i== n-1 and j==m-1 ) return grid[i][j];
// else if(i>=n or j>=m) return 101;
// int down,right;
// down= grid[i][j] + helper(grid, i, j+1, n, m);
// right= grid[i][j] + helper(grid, i+1, j, n,m);
// return min(down, right);


// }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
//         // helper(grid,i, j, n, m)
//        return helper(grid, 0, 0, n, m);
        
//     }
// };

class Solution
//                   MEMOISED SOLUTION(MIGHT UPLOAD TABULATED AND SPACE OPTIMISED SOLUTION LATER)
private:
int helper(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int> > &memo){
     if(i==n or j>=m) return INT_MAX;
if(i== n-1 and j==m-1 ) return grid[i][j];

int down,right;
if(memo[i][j]!=-1) return memo[i][j];
down= helper(grid, i, j+1, n, m, memo);
right=  helper(grid, i+1, j, n,m, memo);
return memo[i][j]= grid[i][j]+  min(down, right);


}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        // helper(grid,i, j, n, m)
        vector<vector<int> > memo(n, vector<int>(m, -1));
       return helper(grid, 0, 0, n, m, memo);
        
    }
};
