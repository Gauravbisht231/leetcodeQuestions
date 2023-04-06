//  THE ENTIRE CODE IS SIMILAR TO -NUMBER OF ISLANDS,BUT WE NEED TO CHECK FOR THE BOUNDARY ISLANDS AS WELL, WHHICH ARE NOT SURROUNDES BY WATER FROM 4 SIDES
class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int ro, int col, int n, int m){
        if(ro<0 or col<0 or ro>=n or col>=m) return ;
        if(grid[ro][col]==1 or vis[ro][col]==true) return;
        vis[ro][col]= 1;
        dfs(grid,vis, ro, col+1, n, m);
        dfs(grid,vis, ro, col-1, n, m);
        dfs(grid,vis, ro+1, col, n, m);
        dfs(grid,vis, ro-1, col ,n, m);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int res=0;
        vector<vector<int>> vis(n, vector<int> (m, false));
        // all first col islands (invalid)
        for(auto i=0; i<n; i++){
                dfs(grid,vis, i, 0, n,m);
                 dfs(grid,vis, i, m-1, n,m);
        }
        // all first row islands(invalid)
        for(auto j=0; j<m; j++){
                dfs(grid,vis, 0, j, n,m);
                 dfs(grid,vis ,n-1, j, n,m);
        }
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] and grid[i][j]==0){
                res++;
                dfs(grid,vis , i, j, n, m);
            }
        }
        }
        return res;
    }
};
