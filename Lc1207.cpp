class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> map;
       for(auto it: arr){
           map[it]++;
       } 
       vector<int> fre;
       for(auto it: map){
           int freq= it.second;
           fre.push_back(freq);
       }
       sort(fre.begin(), fre.end());
       for(int i=0; i<fre.size()-1; i++) if(fre[i]== fre[i+1]) return 0;
       return 1; 
    }
};