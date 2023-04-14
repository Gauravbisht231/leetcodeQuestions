class Solution {
    private:
    int helper(string &s, string &rev, int i, int j, int n, int m, vector<vector<int>> &memo){
        if(i>=n or j>=m) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s[i]==rev[j]) {
            return memo[i][j]= 1+ helper(s, rev, i+1, j+1, n, n, memo);
        }
        else{
            return memo[i][j]= max(helper(s, rev, i+1, j, n, m, memo), helper(s, rev, i, j+1, n, m, memo));
        }
    }

public:
    int longestPalindromeSubseq(string s) {
        string st(s.begin(), s.end());
        reverse(s.begin(), s.end());
        string rev(s.begin(), s.end());
        int i=0, j=0;
        int n= st.size();
        int m= rev.size();
        vector<vector<int>> memo(n, vector<int> (m, -1));
        return helper(st, rev, i,j, n, m, memo);
    }
};
