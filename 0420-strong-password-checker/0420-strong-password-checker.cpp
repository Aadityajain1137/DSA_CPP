class Solution {
public:
    bool checkCapi(string s){
        for(char c : s)
            if(isupper(c)) return true;
        return false;
    }

    bool checkLow(string s){
        for(char c : s)
            if(islower(c)) return true;
        return false;
    }

    bool checkDigit(string s){
        for(char c : s)
            if(isdigit(c)) return true;
        return false;
    }

    int strongPasswordChecker(string password) {
        int n = password.size();

        int missing = 0;
        if(!checkLow(password)) missing++;
        if(!checkCapi(password)) missing++;
        if(!checkDigit(password)) missing++;

        vector<int> groups;
        int replace = 0;
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && password[j] == password[i]) j++;

            int len = j - i;
            if(len >= 3){
                groups.push_back(len);
                replace += len / 3;
            }

            i = j;
        }

        if(n < 6){
            return max(missing, 6 - n);
        }

        if(n <= 20){
            return max(missing, replace);
        }

        int del = n - 20;
        int ans = del;

        for(int i = 0; i < groups.size() && del > 0; i++){
            if(groups[i] % 3 == 0){
                groups[i]--;
                del--;
                replace--;
            }
        }

        for(int i = 0; i < groups.size() && del > 1; i++){
            while(groups[i] >= 4 && groups[i] % 3 == 1 && del >= 2){
                groups[i] -= 2;
                del -= 2;
                replace--;
            }
        }

        for(int i = 0; i < groups.size() && del > 0; i++){
            while(groups[i] >= 3 && del >= 3){
                groups[i] -= 3;
                del -= 3;
                replace--;
            }
        }

        return ans + max(missing, replace);
    }
};