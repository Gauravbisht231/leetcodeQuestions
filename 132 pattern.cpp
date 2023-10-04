class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        //  num[1]< num[3]<num[2]

        // O(N2) approach
        int num1= nums[0];
        for(int j=1; j<n-1; j++){
            num1= min(num1, nums[j]);
            for(int k=j+1; k<n; k++){
                if(num1 < nums[k] and nums[k]< nums[j]) return true;
            }
        }

        return false;
    }
};
