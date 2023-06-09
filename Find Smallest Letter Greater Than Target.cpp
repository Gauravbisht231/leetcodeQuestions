class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo, hi;
        //BSearch tc; O(log(N)) and constant space complexity
        lo= 0, hi= letters.size()-1;
        while(lo<=hi){
            int mid = (hi+lo+1)/2;
            if(mid<letters.size()-1 and letters[mid]<=target and letters[mid+1]>target)return letters[mid+1];
            else if(letters[mid]<=target) lo= mid+1;
            else hi= mid-1;
        }
        return letters[0];
    }
};
