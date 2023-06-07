class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        
        while(a!=0 or b!=0 or c!=0){
            if((c&1)==1){
               
                 if((a&1)==0 and (b&1)==0){
                    res++;
                }
            }
            
            else
            {
              if((a&1)==1) res++;
              if((b&1)==1) res++;
            }
            c>>=1;
            b>>=1;
            a>>=1;
        }
        return res;
    }
};
