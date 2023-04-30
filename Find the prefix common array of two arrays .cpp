//  Leetcode bi-weekly contest 103
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int n= a.size();
        int counter=0;
        if(a.size()==1) {
         res.push_back(a[0]);
            return res;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                int tem= a[j];
                for(int k=0; k<=i; k++){
                    if(b[k]==tem) counter++;
                }
            }
            res.push_back(counter);
            counter=0;
        }
        return res;
    }
};
