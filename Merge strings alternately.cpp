class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        int i=0, j=0;
        string merge;
        while(i<n and j<m){
            merge.push_back(word1[i]);
            merge.push_back(word2[j]);
            i++; j++;
        }
    
    for(i; i<n;i++){
        merge.push_back(word1[i]);
    }
    for(j; j<m; j++){
        merge.push_back(word2[j]);
    }
    return merge;
    }
};
