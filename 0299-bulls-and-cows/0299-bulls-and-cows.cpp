class Solution {
public: 
    
    string getHint(string secret, string guess) {
       unordered_map<char , int> mp;
       for(auto x : secret){
        mp[x]++;
       }
       int cow = 0;
       int bull = 0;
       for(int i=0;i<secret.size();i++){
        if(secret[i] == guess[i]){
            bull++;
            mp[secret[i]]--;
        }
       }
       for(int i=0;i<guess.size();i++){
        if(secret[i] == guess[i]) continue;
        char ch = guess[i];
        if(mp.find(ch)!= mp.end() && mp[ch]>0){
            cow++;
            mp[ch]--;
        }
       }
       return to_string(bull) + "A" + to_string(cow) + "B";
     }
};