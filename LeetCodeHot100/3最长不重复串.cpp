/*
* 题目：在字符串中找到最长不重复的串 返回其长度
* 例如abcdasd 最长不重复的是bcdas 长度为5 返回5
*/

/*
* 方法1：滑动窗口hashmap
* 用哈希表记录每个字符对应的下标
* 以及一个变量记录窗口左端
* 遍历的过程一旦发现当下字符曾经出现过
* 则计算当下长度是否超过maxLength
* 并且更新hashmap中记录的下标为当下
* 最后结束要记得再统计一次是否最后一个字符到之前的长度更大
*/

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ciMap;
        int maxLength = 0, lastFall = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (ciMap.count(s[i])) {
                maxLength = max(maxLength, i - lastFall);
                lastFall = max(lastFall, ciMap[s[i]] + 1);
                ciMap[s[i]] = i;
            }
            else {
                ciMap[s[i]] = i;
            }
        }
        return maxLength > s.size() - lastFall ? maxLength : s.size() - lastFall;
    }
};

/*
* 方法2：滑动窗口vector
* 思想与方法1一致 优化之处在于
* 首先题目给的字符串中只包含ASCII表中有的字符
* 可以用128个大小的vector代替hashmap 下标为ASCII码
* 元素大小记录出现的位置
* 简化循环体为 
* 如果当下字符对应的位置被赋值到>=0过（说明之前出现过）
* 且大于滑动窗口左端 那么更新maxLength和窗口左端
* 同样结束后要考虑最后一个字符对应的情况
*/

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ciMap(128, -1);
        int maxLength = 0, lastFall = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (ciMap[s[i]] >= lastFall) {
                maxLength = max(maxLength, i - lastFall);
                lastFall = ciMap[s[i]] + 1;
            }
            ciMap[s[i]] = i;
        }
        return maxLength > s.size() - lastFall ? maxLength : s.size() - lastFall;
    }
};