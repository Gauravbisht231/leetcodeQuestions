class Solution {
private:
bool isvowel(char c){
    if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u') return 1; else return 0;
}
public:
    int maxVowels(string s, int k) {
        int res=0, counter=0;
        int n= s.size();
        for(int i=0;i<n; i++)
        {
            if(isvowel(s[i])) counter++;
            if(i>=k){ //0 based index
            // if the window size exceeds, we check if the i-kth i.e. first index of the previous window has vowel or not, if yes, then counter is decreased by 1 else remain same
                counter = counter- isvowel(s[i-k]);
            }
            res= max(counter, res);
        }
        return res;
        // O(n*k) approach
    }
};
