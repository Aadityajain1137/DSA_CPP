class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c1= 0 , c2 =0 , c3 =0;
        for(int val : stones){
            if(int type = val%3; type == 0){
                c1++;
            }
            else if(type == 1)c2++;
            else c3++;
        }
        if(c1%2 == 0){
            return c2>=1 && c3>=1;
        }
        return c2 - c3 >2 || c3 - c2 >2;
    }
};