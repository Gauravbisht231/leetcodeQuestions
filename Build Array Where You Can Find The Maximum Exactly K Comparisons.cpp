class Solution {
    int n, m, k;
    int mod= 1e9+7;
    int memo[51][51][101];

private:
int helper(int ind, int searchCost, int maxValue){
    if(ind>=n){
       return searchCost==k? 1:0;
    }
    if(memo[ind][searchCost][maxValue]!=-1) return memo[ind][searchCost][maxValue];
        int count=0;
        for(int element=1; element<=m; element++){
            if(element>maxValue){
                count=(count + helper(ind+1, searchCost+1, element)) %mod;
            }
            else count= (count + helper(ind+1, searchCost,maxValue))%mod;
        }
    
    return memo[ind][searchCost][maxValue]= count%mod;
}
public:
    int numOfArrays(int N, int M, int K) {
        n=N;
        m=M;
        k=K;
        int res=0;
        int searchCost=0, maxValue=0;
        int ind=0;
        memset(memo, -1, sizeof(memo));
        res= helper(ind, searchCost, maxValue);
        return res;
    }
};
