class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto x : s){
            if(st.empty()){
                st.push(x);
            }
            else if(x == '('){
                st.push(x);
            }
            else if(x == ')' && st.top() == '('){
                st.pop();
            }
            else if(x == ')' && st.top() != '('){
                st.push('x');
            }
        }
        return (int)st.size();
    }
};