class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1')
                ones++;

            // Too many 1s -> shrink from left
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Remove unnecessary leading zeros
            while (left < right && s[left] == '0') {
                left++;
            }

            // We have exactly k ones
            if (ones == k) {
                string cur = s.substr(left, right - left + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};