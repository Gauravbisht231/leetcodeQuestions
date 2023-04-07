class Solution {
    // WITHOUT USING ANY EXTRA SPACE
       void dfs(vector<vector<int>>& grid,  int ro, int col, int n, int m, int &res){
        if(ro<0 or col<0 or ro>=n or col>=m) return ;
        if(grid[ro][col]==0) return;
        grid[ro][col]= 0;
        res++;    // update result for every one found 
        dfs(grid, ro, col+1, n, m, res);
        dfs(grid, ro, col-1, n, m, res);
        dfs(grid, ro+1, col, n, m, res);
        dfs(grid, ro-1, col ,n, m, res);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
          int n= grid.size();
        int m= grid[0].size();
        int res=0;
        // all first col islands (invalid)
        for(int i=0; i<n; i++){
                dfs(grid, i, 0, n,m, res);
                 dfs(grid, i, m-1, n,m, res);
        }
        // all first row islands(invalid)
        for(int j=0; j<m; j++){
                dfs(grid, 0, j, n,m, res);
                 dfs(grid, n-1, j, n,m, res);
        }
        res=0;    // reset result for inner valid islands
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
               
                dfs(grid,  i, j, n, m, res);
            }
        }
        }
        return res;
    }
};
