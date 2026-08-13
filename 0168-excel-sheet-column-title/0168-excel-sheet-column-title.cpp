class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string ans;
        while(n>0){
            n--;
            int digit = n % 26;
            ans += 'A' + (digit);
            n/=26;
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};