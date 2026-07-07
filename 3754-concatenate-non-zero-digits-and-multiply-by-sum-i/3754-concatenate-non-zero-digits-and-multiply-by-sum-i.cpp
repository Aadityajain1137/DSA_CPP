class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        vector<int> digits;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                sum += digit;
                digits.push_back(digit);
            }
            n /= 10;
        }

        long long num = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            num = num * 10 + digits[i];
        }

        return num * sum;
    }
};