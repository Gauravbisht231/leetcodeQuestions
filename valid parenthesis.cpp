class Solution {
private:
bool isopening(char sym){
    if(sym=='(' or sym=='{' or sym=='[') return true;
    else return false;
}
bool ispair(char sym, char sttop){
if((sym==']' and sttop=='[')  or (sym==')' and sttop=='(') or (sym=='}' and sttop=='{' )) return true;
    else return false;
}
 
public:
    bool isValid(string s) {
    int n= s.size();
    stack<char> st;
    for(int i=0; i<n; i++){
    char sym= s[i];
    if(isopening(sym)) st.push(sym);
    else {
        if(st.empty()) return false;
        else if(!ispair(sym, st.top())) return false;
        else st.pop();
    }
    }    
    return st.empty();
    }
};
