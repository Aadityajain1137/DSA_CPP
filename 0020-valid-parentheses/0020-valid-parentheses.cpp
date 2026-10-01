class Solution {
public:
    bool matches(char ch , char top){
        if(ch ==')' && top == '(' || ch =='}' && top == '{' || ch == ']' && top =='['){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValid(string s) {
        stack<char> q;
        for(int i =0;i<s.length();i++){
            char ch = s[i];
            if(ch == '(' || ch =='[' || ch =='{'){
                q.push(ch);
            }
            else{
                if(!q.empty()){
                    char top = q.top();
                    if(matches(ch , top)){
                        q.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};