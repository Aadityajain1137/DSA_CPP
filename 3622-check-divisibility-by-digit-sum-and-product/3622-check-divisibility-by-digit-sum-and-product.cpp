class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mult = 1;
        int val = n;
        while(n>0){
            int digit = n %10;
            sum+=digit;
            mult*=digit;
            n = n/10;
        }
        
        return val % (sum + mult) == 0;

    }
};