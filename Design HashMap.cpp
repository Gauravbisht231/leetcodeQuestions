#include<bits/stdc++.h>
using namespace std;
class MyHashMap {
    //          using custom Hashfunction-- bucket method
public:
vector<list<pair<int, int>>> buck;
    MyHashMap() {
        
        buck.resize(10000);
    }
    
    void put(int key, int value) {
     int custom_ind= key%10000;
        auto & chain= buck[custom_ind]; 
        for(auto &it: chain){
            if(it.first==key) {
                it.second= value;
                return;
            }
        } 
        chain.emplace_back(key, value);  
        return;
    }
    
    int get(int key) {
        int custom_ind= key%10000;
        auto & chain= buck[custom_ind];
        for(auto it: chain){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int custom_ind= key%10000;
        auto &chain = buck[custom_ind];
        for( auto it= chain.begin(); it!= chain.end(); it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
            else continue;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
