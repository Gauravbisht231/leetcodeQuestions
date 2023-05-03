class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int res=101;
        int n= blocks.size();
        int ind= n-k;
        for(int i=0;i<=ind; i++){
            string s= blocks.substr(i,k);
            int counter=0;
            for(auto it:s){
                if(it=='W') counter++;
            }
            res= min(res, counter);
        }
        return res;
    }
};
