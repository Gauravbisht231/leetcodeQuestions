/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &s)
    {
        vector<vector<string>> res;
        if (s.size() == 0)
            return {};
        if (s.size() == 1)
            return {s};
        unordered_map<string, vector<string>> mp;
        for (auto it : s)
        {
            auto key = it;
            sort(key.begin(), key.end());
            mp[key].push_back(it);
        }
        for (auto it : mp)
        {
            auto anagrams = it.second;
            res.push_back(anagrams);
        }
        return res;
    }
};