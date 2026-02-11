class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> a(numRows);
        int currRow = 0;
        bool goingDown = false;
        if (numRows == 1 || s.length() <= numRows)
            return s;
        for(char c : s){
            a[currRow]+=c;
            if(currRow == 0 || currRow == numRows-1){
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;

        }
        string result;
        for(string s : a){
            result+=s;
        }
        return result;
    }
};



