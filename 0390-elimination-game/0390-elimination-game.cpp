class Solution {
public:
    int solve(int n , int h , int s , bool left){
        if(n == 1)return h;
        if(left || n%2 ==1) h = h + s;
        n = n/2;
        s*=2;
        left = !left;
        return solve(n , h , s,left);
    }
    int lastRemaining(int n) {
        return solve(n , 1 ,1, true);
    }
};