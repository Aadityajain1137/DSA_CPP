class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string temp = s;
        sort(temp.begin(), temp.end());

        if (temp == s) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (mn == s[0] || mx == s[n - 1]) return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) return 2;
        }

        return 3;
    }
};