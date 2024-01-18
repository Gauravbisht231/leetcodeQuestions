class Solution {
    int helper(int stair,int n, vector<int> &memo){
        if(stair==n) return 1;
        if(stair>n) return 0;
        if(memo[stair]!=-1) return memo[stair];
        return memo[stair]= helper(stair+1, n, memo)  + helper(stair+2, n, memo);

    }
public:
    int climbStairs(int n) {
       int res=0;
       vector<int> memo(n+1, -1);
       res= helper(0, n, memo);
       return res; 
    }
};