/*
* 题目：给定数组 每个数可选正负号
* 求加起来为S的组合数目
*/

/*
* 方法1：题目限定数字不超过20个
* 可使用dfs递归解决 时间复杂度O(2^n)
* 每次判断是否已经处理完全部元素 是的话则判断sum是否等于S
* 都满足则++cnt 否则继续往下分+、-两路
*/
class Solution1 {
    int cnt = 0;
    void dfs(const vector<int>& nums, int i, int sum, int S) {
        if (i == nums.size()) {
            if (sum == S)
                ++cnt;
        }
        else {
            dfs(nums, i + 1, sum + nums[i], S);
            dfs(nums, i + 1, sum - nums[i], S);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0, 0, S);
        return cnt;
    }
};


/*
* 方法2：动态规划
* dp[i][j]表示到达第i个数字时 和为j的组合数目
* 所以dp[i][j+nums[i]] += dp[i-1][j] 
* dp[i][j-nums[i]] += dp[i-1][j]
* 和为(j+nums[i])或者(j-nums[i])都再加上dp[i-1][j]
*/
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, 0));
        dp[0][nums[0] + 1000] += 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < n; ++i)
            for (int sum = -1000; sum <= 1000; ++sum)
                if (dp[i - 1][sum + 1000] > 0) {
                    // 在i-1个数字基础上 +nums[i]
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];

                    // 在i-1个数字基础上 -nums[i]
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }

        return S > 1000 ? 0 : dp[n - 1][S + 1000];
    }
};