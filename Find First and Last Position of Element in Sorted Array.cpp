class Solution {
    //                            BRUTE FORCE
    //         O(N) time and Constant space complexity         
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        int first=-1, second=-1;
        vector<int> res(2,-1);
        // res.push_back(first);
        // res.push_back(second);

        for(int i=0;i<n; i++){
            if(nums[i]==target) {
                first=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i]==target){
                second=i;
                break;
            }
        }
        res[0]=first;
        res[1]=second;
        return res;

    }
};
