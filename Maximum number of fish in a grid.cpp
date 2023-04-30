// Leetcode bi-weekly 103
class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] || grid[r][c] == 0) {
        return 0;
    }
    int fish_caught = grid[r][c];
    grid[r][c] = 0;
    visited[r][c] = true;
    fish_caught += dfs(grid, r+1, c, visited);
    fish_caught += dfs(grid, r-1, c, visited);
    fish_caught += dfs(grid, r, c+1, visited);
    fish_caught += dfs(grid, r, c-1, visited);
    return fish_caught;
}
public:
    int findMaxFish(vector<vector<int>>& grid) {
       
         int max_fish = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != 0) {
                int fish_caught = dfs(grid, i, j, visited);
                max_fish = max(max_fish, fish_caught);
            }
        }
    }
    return max_fish;
    }
};
// class Solution {
//     int helper(vector<vector<int>>& grid), vector<vector<int>> &vis, int i, int j, int n, int m, int &temp){
              
//         if(i>=n or j>=m or i<0 or j<0) return 0;

//         if(!vis[i][j] and grid[i][j]!=0){
//             temp= grid[i][j] + helper(grid, vis, i+1, j, n, m, temp);
//             temp= grid[i][j] + helper(grid, vis, i-1, j, n, m, temp);
//             temp= grid[i][j] + helper(grid, vis, i, j+1, n, m, temp);
//             temp= grid[i][j] + helper(grid, vis, i, j-1, n, m, temp);
            
//         }
//         return temp;
//     }
// public:
//     int findMaxFish(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
//         int res=0;
//         // vector<vector<int>> vis(n, vector<int> (m, false));
//         vector<vector<int>> vis( n , vector<int> (m, 0))
//         for(int i=0; i<n; i++){
// for(int j=0; j<m; j++){
//     int temp=0;
//     if(grid[i][j]!=0 and !vis[i][j]){
//         vis[i][j]=true;
//         res= max(res, helper(grid, vis, i, j, n, m, temp));
//     }
// }}
//         return res;
//     }
// };
