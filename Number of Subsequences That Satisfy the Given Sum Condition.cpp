class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    //   binary search-> a+b= target
    int n= nums.size();
    if(n==1) return 2*nums[0]<= target;
    sort(nums.begin(), nums.end());
      int mod= 1e9+7;
      int res=0;
    //   if works good enough thought process
    vector<int> precomputepower(n,1);
    precomputepower[0]=1;
    for(int i=1; i<n; i++){
       precomputepower[i]= (precomputepower[i-1]*2)%mod;
    }
          int lo= 0, hi= n-1;
          while(lo<=hi){
             
              if(nums[lo]+ nums[hi]<= target){
                 int diff= hi-lo;
                 res= (res%mod + precomputepower[diff])%mod ;
                 lo++;   
              }
              else hi--;
      }
      return res%mod;
    }
};
