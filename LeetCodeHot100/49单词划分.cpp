/*
* 题目：给定字符串s和一集合dict
* 看是否s能完全被划分为dict中的元素
*/

/*
* 方法1：动态规划
* dp[i] 表示字符串s前i个字符组成的字符串是否在dict中
* 每一步判断从j到i的子串是否存在于dict
* 若存在且从0到当下位置的子串也存在
* 对应的dp设为true
*/
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        if (size == 0)
            return false;
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        for (int i = 1; i < size + 1; ++i)
            for (int j = 0; j < i; ++j)
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    // substre(j,i-j)意味着从j开始长度i-j 即是j到i索引
                    // 判断条件意味着s.substr(0,j), s.substr(j,i-j)两段都在
                    // 向后动态规划
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};