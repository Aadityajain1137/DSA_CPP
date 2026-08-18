// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n= s.length();
//         int len = 0;
//         for(int i = 0;i<n;i++){
//             vector<int> hash(256,0);
//             int maxLen = 0;
//             for(int j=i;j<n;j++){
//                 if(hash[s[j]]==1){
//                     break;
//                 }
//                 hash[s[j]]=1;
//                 maxLen = j-i+1;
//                 len = max(len,maxLen);
               
//             }
//         }
//         return len;
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.length();
    
       int i = 0;
       int j = 0;
       int maxLen = 0;
       unordered_map<char,int> mp;
       while(j<n){
        mp[s[j]]++;
        if(mp[s[j]]>1){
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
        }
        int len = j - i +1;
        j++;
        maxLen = max(len , maxLen);
       }
       return maxLen;
    }
};