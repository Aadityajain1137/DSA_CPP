// class Solution {
// public:
//     bool checkValidString(string s) {
//         int n = s.size();
//         int cnt =0;
//         stack<char> st;
//         for(int i=0;i<s.size();i++){
//             if(s[i] == '(') st.push(s[i]);
//             else if(s[i] == '*') cnt++;
//             else {
//                 if(!st.empty()) st.pop();
//                 else if(cnt !=0) cnt--;
//                 else return false;
//             }
//         }
//         return st.size<= cnt;
//     }
// };
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> o;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                o.push(i);
            }
            else if(s[i]=='*'){
                st.push(i);
            }
            else{
                if(!o.empty()){
                    o.pop();
                }
                else if(!st.empty()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!o.empty()){
            if(st.empty()) return false;
            else if(o.top()>st.top()) return false;
            else{
                o.pop();
                st.pop();
            }
        }
        return true;
    }
};