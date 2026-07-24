class Solution {
public:
    bool checkLo(string s){
        for(auto x : s){
            if(islower(x)){
                return true;
            }
        }
        return false;
    }
    bool checkUp(string s){
        for(auto x : s){
            if(isupper(x)){
                return true;
            }
        }
        return false;
    }
    bool checkNo(string s){
        for(auto x : s){
            if(isdigit(x)) return true;
        }
        return false;
    }
    bool checkCon(string s){
        int n = s.length();
        for(int i=1;i<n;i++){
            if(s[i-1] == s[i]) return false;
        }
        return true;
    }
    bool checkSp(string s){
        for(auto x : s){
            if(x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '^' || x == '&' || x == '*'  || x == '('  || x == ')' || x == '-' || x == '+') return true;
        }
        return false;
    }
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n<8) return false;
        if(checkLo(password) && checkUp(password) && checkNo(password) && checkCon(password) && checkSp(password)) return true;
        return false;
    }
};