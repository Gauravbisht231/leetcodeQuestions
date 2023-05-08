class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n= mat.size(); //square matrix
        int res=0;
        for(int i=0; i<n; i++){
            res+= mat[i][i];
        }
        int i=0;
        for(int j=n-1; j>=0 and i<n; j-- ){
                    if(i!=j) res+=mat[i++][j];
                    else i++;
        }
        return res;
    }
};
