class Solution {
private:
int n;
int binarySearchInd(int curInd,int endInd,  vector<vector<int>> &p){
    int lo=curInd, hi= n-1;
    int ind=-1;
    while(lo<=hi){
        int mid= lo + (hi-lo)/2;
        if(p[mid][0]>= endInd){
            ind= mid;
             hi= mid-1;}
        else lo= mid+1;
    }
    return ind;
//     for(int i=curInd; i<n; i++){
//        if(p[i][0]> curInd) return i;
//    }
//    return -1;
}
int helper(int ind , vector<vector<int>> &p,vector<int> &memo){
    if(ind>= n or ind==-1) return 0;
    if(memo[ind]!=-1) return memo[ind];
    // we have two choices: pick or not pick
    int pick=0, notpick=0;
    int nextInd= binarySearchInd(ind,p[ind][1], p);
    pick= p[ind][2] + helper(nextInd, p, memo);
    notpick= 0 + helper(ind+1, p, memo);
    return memo[ind]= max(pick, notpick);
}
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        vector<vector<int>> p;
        n= profit.size();
        vector<int> memo(50001, -1);

        for(int i=0;  i<n; i++){
            p.push_back({s[i], e[i], profit[i]});
        }
        sort(p.begin(), p.end());
        int money= helper(0, p, memo);
        return money;
    }
};