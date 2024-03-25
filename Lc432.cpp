/*
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
*/
#include<bits/stdc++.h>
using namespace std;
class AllOne {
public:
unordered_map<string, int> mp;
set<pair<int, string>> st;
int mini, maxi;
    AllOne() {
        maxi= -1e9;
        mini= 1e9;
    }
    
    void inc(string key) {
        if(mp.find(key)!= mp.end()){
            int fr= mp[key];
            mp[key]++;
            auto pos= st.find({fr, key});
            st.erase(pos);
            st.insert({fr+1, key});
        }else{
            mp[key]++;
            st.insert({1, key});
        }
    }
    
    void dec(string key) {
        if(mp.find(key)!= mp.end()){
            int fr= mp[key];
            mp[key]--;
            auto pos= st.find({fr, key});
            st.erase(pos);
            if(mp[key]==0){
                mp.erase(key);
                return;
            }
            st.insert({fr-1, key});
        }
    }
    
    string getMaxKey() {
        if(st.size()>0)
        return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(st.size()>0)
        return st.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */