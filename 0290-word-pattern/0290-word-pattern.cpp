class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char , string> mp;
        unordered_map<string , char> mp1;
        stringstream ss(s);
        string word;
        int i =0;
        while(ss >> word){
             if (i == pattern.size())
                return false;
                char ch = pattern[i];
            if(mp.find(ch)!= mp.end() && mp[ch] != word){
                return false;
            }
            if(mp1.find(word)!=mp1.end() && mp1[word] != ch) return false;
            mp[ch] = word;
            mp1[word] = ch;
            i++;
        }
        return i == pattern.size();
    }
};