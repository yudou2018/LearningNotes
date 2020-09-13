/*
* 给定一个字符串 计算多少个回文子串
* 例如"abc" 有3个 "a" "b" "c"
* "aaa"有6个 "a" "a" "a" "aa" "aa" "aaa"
*/

/*
* 方法1：中心拓展
* 对每个位置开始左右拓展比对是否回文串
*/
class Solution1 {
    int cnt = 0;
    void helper(const string& s, int left, int right) {
        while (left >= 0 && left < s.length() && s[left] == s[right]) {
            ++cnt;
            --left;
            ++right;
        }
    }
public:
    int countSubstrings(string s) {
        if (s.length() == 0) return 0;
        for (int i = 0; i < s.length(); ++i) {
            helper(s, i, i); // 回文串长度为奇数 中间只有一个字符
            helper(s, i, i + 1); // 回文串长度为偶数 中间有两个字符
        }
        return cnt;
    }
};