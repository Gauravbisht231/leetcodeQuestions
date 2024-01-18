#include<bits/stdc++.h> 
using namespace std;
class RandomizedSet {
vector<int> nums;
unordered_map<int, int> mp;
int i=-1;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if(mp.find(val)== mp.end()){
            i++;
            mp[val]= i;
            nums.push_back(val);
            return true;
        }
        return false;
    }
    bool remove(int val) {
        if(mp.find(val)!= mp.end()){
            int ind= mp[val];
            nums[ind]= nums[i];
            mp[nums[ind]]= ind;
            nums.pop_back();
            mp.erase(val);
            i--;
            return true;
        }
        return false;
    }
    int getRandom() {
       return nums[rand()%(i+1)];
    }
};