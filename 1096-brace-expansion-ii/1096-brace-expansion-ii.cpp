class Solution {
public:
    set<string> parse(string& s, int& i) {
        set<string> result;
        set<string> current;
        current.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                for (auto& str : current) {
                    result.insert(str);
                }

                current.clear();
                current.insert("");
                i++;
            } else {
                set<string> temp;

                set<string> next;

                if (s[i] == '{') {
                    i++;
                    next = parse(s, i);
                    i++;
                } else {
                    next.insert(string(1, s[i]));
                    i++;
                }

                for (auto& a : current) {
                    for (auto& b : next) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
        }

        for (auto& str : current) {
            result.insert(str);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};