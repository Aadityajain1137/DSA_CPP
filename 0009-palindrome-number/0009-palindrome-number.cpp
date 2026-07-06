class Solution {
public:
    long long solve(int x){
        long long rev = 0;
        while(x){
            int digit = x%10;
            rev = rev*10 + digit;
            x = x/10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        long long rev = solve(x);
        if(x<0) return false;
        if(x == rev) return true;
        return false;
    }
};