class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> map(n, 0);
        vector<int> res;
        int i=0; int ind=0;
        while(true){
            int nex= (ind + i*k)%n;
            if(map[nex]==1) break;
            map[nex]++;
            ind= nex;
            i++;
        }
        for(int i=0;i<n; i++){
            if(map[i]==0) res.push_back(i+1);
        }
        return res;
    }
};
