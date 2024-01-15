#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string s, string t) {
        int n= s.size(), m= t.size();
        if(m!=n) return false;
        // sort(s.begin(), s.end()), sort(t.begin(), t.end());
       vector<int> sf(26, 0), tf(26, 0);
       for(auto it: s){
           sf[it-'a']++;
       }
       for(auto it: t){
           tf[it-'a']++;
           if(sf[it-'a']==0) return false;
       }
       sort(sf.begin(), sf.end()), sort(tf.begin(), tf.end());
       return sf==tf;
    }
};