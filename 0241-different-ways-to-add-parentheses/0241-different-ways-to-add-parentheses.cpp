class Solution {
public:
    unordered_map<string,vector<int>> mp;
    vector<int> solve(string ex){
        if(mp.count(ex)) return mp[ex];
        vector<int> result;
        for(int i=0;i<ex.size();i++){
            if(ex[i] != '+' && ex[i] != '-' && ex[i] != '*'){
                continue;
            }
            string leftt = ex.substr(0 , i);
            string rightt = ex.substr(i+1);
            vector<int> left = solve(leftt);
            vector<int> right = solve(rightt);
            for(int a : left){
                for(int b : right){
                    if(ex[i] == '+'){
                        result.push_back(a + b);
                    }
                    else if(ex[i] == '-'){
                        result.push_back(a - b);
                    }
                    else{
                        result.push_back(a * b);
                    }
                }
            }
        }
        if(result.empty()){
                result.push_back(stoi(ex));
        }
        mp[ex] = result;
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};