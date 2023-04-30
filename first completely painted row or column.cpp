// leetcode weekly contest 343 medium question -> 30/4/23
class Solution {
public:
        int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat){
        int ro=mat.size();
        int col=mat[0].size();
        vector<int>r(ro,0);
        vector<int>c(col,0);
        unordered_map<int,pair<int,int>>naksha; // element to [r][c]
        for(int i=0;i<ro;i++)
        {
            for(int j=0;j<col;j++)
            {
                // m.insert({mat[i][j],{i,j}});
                naksha[mat[i][j]]= {i, j};
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            int x=naksha[arr[i]].first;
            int y=naksha[arr[i]].second;
            r[x]++;
            c[y]++;
            if(r[x]==col)
                return i;
            if(c[y]==ro)
                return i;
        }
        return arr.size()-1;
    }
};
