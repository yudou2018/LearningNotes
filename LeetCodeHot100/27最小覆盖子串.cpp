/*
* 题目：字符串S、T，要求在O(n)时间复杂度下找到S中覆盖T的最小长度子串
* 例如S = "ADOBECODEBANC", T = "ABC"
* 返回 "BANC"
*/


/*
* 方法1：滑动窗口
* 利用unordered_map计数 当cntS中的所有t中字符个数达到不小于cntT时
* 统计长度 如果小于当前最小 那么更新 minLength 和 range
* 最后根据range返回子串
*/
class Solution1 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cntS, cntT;
        for (int i = 0; i < t.size(); ++i)
            ++cntT[t[i]];
        int left = 0, right = 0, minLength = INT_MAX;
        pair<int, int> range;
        s += " ";
        auto check = [&]()->bool {
            for (auto const& cT : cntT)
                if (cntS[cT.first] < cT.second)
                    return false;
            return true;
        };
        while (right < s.size()) 
            if (check()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    range = { left,right };
                }
                --cntS[s[left++]];
            }
            else
                ++cntS[s[right++]];
        
        return right == s.size() ?
            s.substr(range.first, range.second - range.first) :
            s.substr(range.first, range.second - range.first + 1);
    }
};