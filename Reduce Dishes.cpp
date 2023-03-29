// class Solution {
//     //                          RECURSIVE APPROACH(MIGHT GIVE TLE)
//     // 0/1 knapsack pattern problem
// private:
// int helper(vector<int> &s, int ind, int time, int n){
//     if(ind>= n) return 0;
//     // now we have two path, either chose the current index 
//     // or exclude the current index
//     int include= s[ind]*(time) + helper(s, ind+1, time+1,n);
//     int exclude= 0 +  helper(s, ind+1, time,n);
//     return max(include, exclude);

// }
// public:
//     int maxSatisfaction(vector<int>& s) {
//        int n= s.size();
//        sort(s.begin(), s.end());
//     //    helper(satisfaction, starting index, time, size of satisfaction array )
//        return helper(s, 0,1, n);
//     }
// };



// // The aim of sorting is if we want to take some negative satisfaction then we must take it as early as possible. Less the satisfaction earlier we must take it. And the rest is basic DP.





class Solution {
    //                          MEMOISED APPROACH(TC- O(N2) and SC- O(N2))
    // 0/1 knapsack pattern problem
private:
int helper(vector<int> &s, int ind, int time, int n, vector<vector<int>> &memo){
    if(ind>= n) return 0;
    // now we have two path, either chose the current index 
    // or exclude the current index
    if(memo[ind][time]!=-1) return memo[ind][time];
    int include= s[ind]*(time) + helper(s, ind+1, time+1,n, memo);
    int exclude= 0 +  helper(s, ind+1, time,n, memo);
    return memo[ind][time]=max(include, exclude);

}
public:
    int maxSatisfaction(vector<int>& s) {
       int n= s.size();
       sort(s.begin(), s.end());
       vector<vector<int>> memo(n+1, vector<int> (n+1, -1));

    //    helper(satisfaction, starting index, time, size of satisfaction array , dp vector)
       return helper(s, 0,1, n, memo);
    }
};



// The aim of sorting is if we want to take some negative satisfaction then we must take it as early as possible. Less the satisfaction earlier we must take it. And the rest is basic DP.
