class Solution {
    //                            tRYING OPTIMISING IT: BINARY SEARCH
    //                       O(log(n)) time and Constant space complexity     

private:
int Bsfirst(vector<int> &nums, int target, int n){
    int ind=-1;
    int lo=0, hi= n-1;
    while(lo<=hi)
    {
        int mid= lo+(hi-lo)/2;
        if(nums[mid]== target){
            // if we have reached out to first index
            if(mid==0 or nums[mid-1]!=target){
                    ind= mid;
                    break;
            }
            //  else keep on searching in the  left half
            else {
                hi= mid-1;
            } 
        }
        else if(nums[mid]< target){
            lo= mid+1;
        }
        else hi= mid-1;
    }
    return ind;

}   
int BsSecond(vector<int> &nums, int target, int n){
    int second=-1;
    int lo=0, hi= n-1;
    while(lo<=hi){
        int mid= lo+(hi-lo)/2;
        if(nums[mid]== target){
            // if we have reached out to Last index of occurence
            if(mid==n-1 or nums[mid+1]!=target){
                second= mid;
                break;
            }
            // else keep on finding the last index in the right half
            else {
                lo= mid+1;
            }
        }
        else if(nums[mid]<target){
            lo= mid+1;
        }
        else hi= mid-1;
    }
    return second;
} 
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        int first=-1, second=-1;
        vector<int> res(2,-1);
        int lo=0, hi= n-1;
        first= Bsfirst(nums, target, n);
        second= BsSecond(nums, target, n);
        res[0]= first;
        res[1]= second;
        return res;
    }
};
