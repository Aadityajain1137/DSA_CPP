class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = 1;
        int i = 0;
        int j = 0;
        int n = s.length();
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]>2){
                while(mp[s[j]]>2){
                    mp[s[i]]--;
                    i++;
                }
            }
            int l = j - i +1;
            len = max(l , len);
            j++;
        }
        return len;
    }
};