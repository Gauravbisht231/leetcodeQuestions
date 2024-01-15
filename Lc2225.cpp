#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res;
        unordered_map<int, int> lost;
        set<int> st;
        for(auto it: matches){
            auto winner= it[0];
            auto loser= it[1];
            st.insert(winner);
            st.insert(loser);
            lost[loser]++;
        }
        vector<int> allWin, loseOne;
        for(auto player: st){
            if(lost.find(player)== lost.end()) allWin.push_back(player);
            if(lost[player]==1) loseOne.push_back(player);
        }
        res.push_back(allWin), res.push_back(loseOne);
        return res;
    }
};