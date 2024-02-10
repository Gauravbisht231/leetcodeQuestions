/*
                                Sort Characters By Frequency
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        set<pair<int, char>> st;
        unordered_map<char, int> mp;
        for(auto it: s) mp[it]++;
        for(auto  it: mp){
            int freq= it.second;
            char ch= it.first;
            st.insert({freq, ch});
        }
        string res="";
        for(auto it: st){
            int times= it.first;
            for(int i=0; i<times; i++) res+= it.second;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};