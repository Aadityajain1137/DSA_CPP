class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()<2) return s;
        sort(s.begin(), s.end());

        int n = s.size();
        vector<char> ans(n);

        int l = 0, r = n - 1;
        int i = 0;

        while (i < n) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                ans[n / 2] = s[i];
                i++;
            } else {
                ans[l] = s[i];
                ans[r] = s[i];
                l++;
                r--;
                i += 2;
            }
        }

        return string(ans.begin(), ans.end());
    }
};