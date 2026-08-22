class Solution {
public:
    void solve(string s , int left , int right , int &count,int n){
        if(left <0 || right >=n) return;
        if(s[left] != s[right]) return;
        count++;
        solve(s , left - 1 , right+1 ,count, n);
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count =0;
        for(int mid = 0;mid<n;mid++){
            solve(s , mid , mid , count , n);
        }
        for(int mid = 0;mid<n-1;mid++){
            solve(s , mid , mid+1 , count , n);
        }
        return count;
    }
};