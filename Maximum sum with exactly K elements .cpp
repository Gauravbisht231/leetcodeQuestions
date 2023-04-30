// leetcode bi-weekly contest 103
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int res=0;
        int maxi= *max_element(nums.begin(), nums.end());
        for(int i=0; i <k; i++){
            res+= maxi +i;
        }
        return res;
    }
};
