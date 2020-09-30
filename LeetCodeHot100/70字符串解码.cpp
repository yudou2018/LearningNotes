/*
* 题目：s="3[a]2[bc]" 返回 "aaabcbc"
* s="3[a2[c]]" 返回 "accaccacc"
*/

class Solution {
public:
    pair<string, int> solver(const string& s, int i) {
        int multiplier = 0;
        string ans = "";
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                multiplier = multiplier * 10 + s[i] - '0'; // 有可能是两位数、三位数...
            }
            else if (s[i] == '[') {
                auto sub_ans = solver(s, i + 1);
                i = sub_ans.second;
                while (multiplier > 0) {
                    ans += sub_ans.first;
                    --multiplier;
                }
            }
            else if (s[i] == ']') {
                return pair(ans, i);
            }
            else {
                ans += s[i];
            }
            ++i;
        }
        return pair(ans, i);
    }
    string decodeString(string s) {
        return solver(s, 0).first;
    }
};