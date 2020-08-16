/*
* 题目：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
* 数字对应的是手机九宫格输入法的字母 2对应abc 3对应def...
*/

/*
* 方法1：回溯算法递归（其实不是dfs或bfs因为每个元素都被遍历了不止一次）
* 首先记录下被摁下的号码 存到dctnry中
* dfs函数传入的有当下索引、当下字符串
* 首先传入空串 将i+1和temp+touch[i][j]调用dfs
* 直到传入的i指示越界 放入temp
* 递归自动回溯至之前的状态temp还没有加上touch[i][j]的状态
* 此时由于循环 加上下一个
* 时间复杂度O(3^N*4^M) 排列组合
* 空间复杂度O(3^N*4^M) 需要保存3^N*4^M个结果
*/

class Solution {
    vector<string> ans;
    vector<vector<char>> dctnry{ {'!'},{'!'},{'a','b','c'},{'d','e','f'},{'g','h','i'},
            {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
    void dfs(vector<vector<char>>& touch, int i,string temp) {
        if (i == touch.size()) { // 如果i指示越界 放入传入的temp
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < touch[i].size(); ++j) { // 循环传入temp加不同字符
            dfs(touch, i + 1, temp + touch[i][j]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // 如果digits是空的 本题要求返回的是{}而非{""}
        vector<vector<char>> touch;
        for (int i = 0; i < digits.size(); ++i)
            touch.push_back(dctnry[digits[i] - '0']);
        dfs(touch, 0, "");
        return ans;
    }
};