class Solution {
public:
// optimised yet easiest to understand: two queue
    string predictPartyVictory(string senate) {
      queue<int> rad, dir;
int n= senate.size();
for(int i=0; i<n; i++){
    if(senate[i]=='R') rad.push(i);
    if(senate[i]=='D') dir.push(i);
}
while(!rad.empty() and !dir.empty()){
    auto radfront= rad.front();
    auto dirfront= dir.front();
    if(radfront<dirfront){
        rad.pop();
        dir.pop();
        rad.push(n+radfront-1);
    }
    else {
        rad.pop();
        dir.pop();
        dir.push(n+dirfront-1);
    }
}
if(rad.empty()==true) return "Dire";
else return "Radiant";
    }
};
