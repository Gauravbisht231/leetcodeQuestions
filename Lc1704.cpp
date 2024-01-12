class Solution {
public:
    bool halvesAreAlike(string s) {
      set<char> st={'a','e','E','A','i','I','o','O','u','U'};
      int n= s.size();
      int lc=0, rc=0;
      for(int i=0; i<n/2; i++){
          if(st.find(s[i])!= st.end()) lc++;
          char rightChar= s[i+n/2];
          if(st.find(rightChar)!= st.end()) rc++;
      }
      return lc==rc;
    }
};