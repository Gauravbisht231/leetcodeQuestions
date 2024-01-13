class Solution {
public:
    int minSteps(string s, string t) {
    int n= s.size();
    int res=0;
    unordered_map<char, int> smap, tmap;
    for(auto it: s) smap[it]++;
    for(auto it: t) tmap[it]++;
    for(auto it: tmap){
        char ch= it.first;
        int freq= it.second;
        if(freq > smap[ch]) res+= abs(freq-smap[ch]);
        if(smap.find(ch)== smap.end())res++;
    }


    return res;
    }
};