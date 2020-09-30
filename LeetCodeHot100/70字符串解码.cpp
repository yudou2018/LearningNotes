/*
* ��Ŀ��s="3[a]2[bc]" ���� "aaabcbc"
* s="3[a2[c]]" ���� "accaccacc"
*/

class Solution {
public:
    pair<string, int> solver(const string& s, int i) {
        int multiplier = 0;
        string ans = "";
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                multiplier = multiplier * 10 + s[i] - '0'; // �п�������λ������λ��...
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