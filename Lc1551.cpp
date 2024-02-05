#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(int n) {
    int op=0;
    int median= n;
    for(int i=0; i<(n/2); i++){
        int curEle= (2*i)+1;
        op+= abs(median-curEle);
    }

     return op;   
    }
};