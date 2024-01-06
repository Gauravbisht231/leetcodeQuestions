// O(NLogN) approach--> binary search 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=1;
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]> vec.back()) {
                len++;
                vec.push_back(nums[i]);}
            else {
                int changeInd= lower_bound(vec.begin(), vec.end(), nums[i])- vec.begin();
                vec[changeInd] = nums[i];
            }
        }
return len;
    }
};