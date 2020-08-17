/*
* 题目：给你一个字符串 s 和一个字符规律 p，
* 请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
* '.' 匹配任意单个字符 '*' 匹配零个或多个前面的那一个元素
* "misssissppi"对应
* "mis*is*p*." 返回true
*/

/*
* 方法1：动态规划
* 用dp[i][j]表示 s前i个字符 能够匹配 p前j个字符形成的要求
* i、j表示前i个 前j个 所以字符串下标对应的是i-1 j-1
* 如果p[j-1]不是* 只要 s的前i-1部分 和 p的前j-1部分匹配 dp[i][j]=true
* 如果p[j-1]是* 只要以下两种情况符合其一即可：
* 1. s[i-1]与p[j-2]两个字符是匹配的（对应输入函数match(i,j-1)）
*   说明当下s字符与*前的字符相符合 则dp[i][j]由dp[i-1][j]决定
*   只要s的前i-1个满足整个p的要求 则s前i个也满足p整个要求
* 2. 当下字符到p的前j-2部分都符合 即除去 .* 或者 字母* 也符合
*    当下dp[i][j]就符合
*/

class Solution1 {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j)->bool {
            if (i == 0) // 排除一开始越界情况
                return false;
            if (p[j - 1] == '.') // j代表前j个 对应末位字符是p[j-1]
                return true;
            return s[i - 1] == p[j - 1];
        };
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j] | dp[i][j - 2]; // 除去.* 或 字母* 符合则true
                    if (match(i, j - 1))
                        dp[i][j] = dp[i][j] | dp[i - 1][j]; // 字符与*前一个匹配
                    // 那么只要s前i-1个满足整个p的要求即true
                }
                else {
                    if (match(i, j)) // 当下p字符不为* 则看是否当下s字符匹配当下p字符
                        dp[i][j] = dp[i - 1][j - 1]; // 当下匹配 取决于s前i-1和p前j-1是否匹配
                    
                    // 否则当下不匹配 默认初始化dp全false 保持dp[i][j]=false
                }
            }
        return dp[m][n]; // s的前m个与p的前n个的匹配情况
    }
};