class Solution {
public:
    int beautySum(string s) {
        int b= 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            vector<int> freq(26 , 0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxi = 0;
                int mini =INT_MAX;
                for(int i=0;i<26;i++){
                    if(freq[i]>0){
                        mini = min(mini , freq[i]);
                        maxi = max(maxi , freq[i]);
                    }
                }
                b += maxi - mini;
            }
        }
        return b;
    }
};