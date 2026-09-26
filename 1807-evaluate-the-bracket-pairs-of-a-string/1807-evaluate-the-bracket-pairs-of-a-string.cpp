class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (auto& it : knowledge) {
            mp[it[0]] = it[1];
        }
        string ans = "";
        int prevIndex = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                string key = "";
                i++;
                while(s[i]!=')'){
                    key += s[i];
                    i++;
                }
                 if (mp.count(key)) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};