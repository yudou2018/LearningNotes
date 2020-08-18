/*
* 题目：给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
* "(()" 返回2 最长有效括号子串为 "()"
* ")()())" 返回4 最长有效括号子串为 "()()"
*/

/*
* 方法1：暴力法
* 以每个位置开始做起点检查后面是否有balance==0
* 一旦遇到balance==0 比较一次
* 一旦遇到balance<0说明此时右括号多了 陷入无效 thisLength,balance归零
* O(N^2) 超时
*/

class Solution1 {
public:
    int longestValidParentheses(string s) {
        int balance = 0, maxLength = 0, thisLength = 0;
        for (int j = 0; j != s.size(); ++j) {
            balance = 0, thisLength = 0;
            for (int i = j; i != s.size(); ++i)
                if (s[i] == '(') {
                    ++balance;
                    ++thisLength;
                }
                else {
                    --balance;
                    ++thisLength;
                    if (balance == 0) {
                        maxLength = max(maxLength, thisLength);
                    }
                    else if (balance < 0) {
                        thisLength = 0;
                        balance = 0;
                    }
                }
        }
        return maxLength;
    }
};


/*
* 方法2：动态规划
* dp数组记录每个')'对应的有效长度
* 
* 只有')'才有可能作为有效括号的结尾
* 1. ')'之前是'(' 只需要在这个"()"之前记录的有效长度上+2即可；
* 2. ')'之前是')'则查看之前的')'对应的有效长度
*   当下索引减去之前的')'对应的有效长度减1后对应的如果是'('
*   说明当下情况是"( (..有效..) )"一对括号内包含一块有效长度
*   所以是dp[i-1]+2 还要加上在这整个"( (..有效..) )"之前的有效长度dp[i-dp[i-1]-2]
* 时间复杂度O(N) 只遍历一遍
* 空间复杂度O(N) dp数组是长度n
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), maxLength = 0;
        if (n < 2) return 0; // 长度小于2的肯定不符合
        vector<int> dp(n, 0);
        if (s[1] == ')' && s[0] == '(') dp[1] = 2, maxLength = 2; // 开始就是"()" 记录下
        for (int i = 2; i != n; ++i)
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = dp[i - 2] + 2; // 当前两个是"()"则在之前的基础上+2
                maxLength = max(maxLength, dp[i]);
            }
            else if (s[i] == ')' && s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                // 当前是"))" 则考虑前一个)是否有效配对
                // 如果没有 则 i-dp[i-1]-1 = i-0-1 = i-1 显然s[i-1]是')'不符合判断条件
                // 如果有配对 那么i-dp[i-1]-1恰好是前一个')'配对的整段之前一个 如果恰好又是'('
                // 那么完成配对 "( (..有效..) )"dp[i]=dp[i-1]+2 
                // 如果索引i-dp[i-1]-2有效的话 还要加上整个"( (..有效..) )"之前的dp[i-dp[i-1]-2]
                if (i - dp[i - 1] - 2 >= 0) dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
                else dp[i] = 2 + dp[i - 1];
                maxLength = max(maxLength, dp[i]);
            }
        return maxLength;
    }
};