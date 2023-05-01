class Solution {
public:
    double average(vector<int>& s) {
        double res=0;
        sort(s.begin(), s.end());
        int n= s.size();

        for(int i=1; i<n-1; i++){
            res+=s[i];
        }
        // O(NlogN) approach
        res= double(res)/(n-2);
        return res;
    }
};
