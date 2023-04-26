class Solution {
    // learnt something new from discussion section
public:
    int addDigits(int n) {
        if(n==0) return n;
        else if(n%9==0) return 9;
        else return n%9;
    }
};

// class Solution {
// public:
//     int addDigits(int num) {
//         if(num==0) return 0;

//      int sum=0;
//      while(num>0){
//         sum+=num%10; 
//         num= num/10;
//      }  
//      num= sum; 
//      if(num>9) return addDigits(num);
//      return num;
//     }
// };
