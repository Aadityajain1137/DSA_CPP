class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26 , n);
        vector<int> last(26 , -1);
        for(int i=0;i<n;i++){
            int x = s[i]-'a';
            first[x] = min(first[x] , i);
            last[x] = i;
        }
        vector<pair<int,int>> intervals;
        for(int i = 0;i<26;i++){
            if(last[i] == -1) continue;
            int start = first[i];
            int end = last[i];
            bool isValid = true;
            for(int x = start;x<=end;x++){
                int c = s[x] - 'a';
                if(first[c]<start){
                    isValid = false;
                    break;
                }
                end = max(end , last[c]);
            }
             if (isValid) {
                intervals.push_back({start, end});
            }
        }
         sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[start, end] : intervals) {
            if (start > prevEnd) {
                ans.push_back(s.substr(start, end - start + 1));
                prevEnd = end;
            }
        }

        return ans;
    }
};