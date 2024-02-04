#include<bits/stdc++.h>
using namespace std;
class Solution {
    /*
    Do not maintain the string variable and update it every time you find a
    better minimum substring. Instead maintain pointers and create substring
    only once, otherwise there will be TLE/MLE*/
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n < m)
            return "";

        unordered_map<char, int> mp;
        for (auto it : t)
            mp[it]++;
        int counter = mp.size();
        int starting_ind;
       
        int i = 0, j = 0;
        int minlen = 1e9;
        // traversing over s with  i,j pointers
        while (j < n) {
            char jel = s[j];
            if (mp.find(jel) != mp.end()) {
                mp[jel]--;
                if (mp[jel] == 0)
                    counter--;
            }
            while (counter ==
                   0) { // this window is our one of the possibilities
                char iel = s[i];
                // minlen= min(minlen, j-i+1); //  dont do this,as it wil keep
                // updating the result string everytime :-)
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    starting_ind= i;
                    // res = s.substr(i, minlen);
                }
                if (mp.find(iel) == mp.end())
                    i++;
                else {
                    mp[iel]++;
                    if (mp[iel] == 1)
                        counter++;
                    i++;
                }
            }
            j++;
        }
        //now we have starting_ind in S and minlen
        return minlen==1e9?"": s.substr(starting_ind, minlen);
        
    }
};