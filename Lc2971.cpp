class Solution {
public:
typedef long long ll;
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        ll pre= nums[0];
        ll res=-1;
        for(int i=1; i <n-1;  i++){
            pre+= nums[i];
            if(pre> nums[i+1]) res= (ll)(nums[i+1] + pre);
            else continue;
        }
        return res;
        
    }
};