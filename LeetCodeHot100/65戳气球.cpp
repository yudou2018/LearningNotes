/*
* 题目：戳气球
* 如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币
*/

/*
* 方法1：回溯
* 遍历数组 传入当下选择气球得到的coins 维护一个最大值ans
* 每次erase戳破后要insert放回
*/
class Solution1 {
    void helper(vector<int>& nums, int coins, int& ans) {
        if (nums.size() == 0) {
            ans = max(ans, coins);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i]; //  中间
            int delta = nums[i] * (i - 1 < 0 ? 1 : nums[i - 1]) * (i + 1 > nums.size() - 1 ? 1 : nums[i + 1]); // 左右
            nums.erase(nums.begin() + i);
            helper(nums, coins + delta, ans);
            nums.insert(nums.begin() + i, tmp); // 放回 继续遍历找最大
        }
    }
public:
    int maxCoins(vector<int>& nums) {
        int ans = 0;
        helper(nums, 0, ans);
        return ans;
    }
};

/*
* 方法2：二维动态规划
* dp[i][j]表示第i到第j个气球的最优解
*/
class Solution2 {
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] > 0) return dp[i][j];
        for (int k = i; k <= j; ++k) {
            int left = helper(nums, i, k - 1);
            int right = helper(nums, k + 1, j);
            int delta = nums[k] * nums[i - 1] * nums[j + 1];
            dp[i][j] = max(dp[i][j], left + right + delta);
        }
        return dp[i][j];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
        int ans = helper(nums, 1, n);
        return ans;
    }
};

/*
* 方法3：二维动态规划优化
* dp[i][j]表示第i到第j个气球的最优解
*/
class Solution3 {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int len = 1; len <= n; ++len) {
            // i<n-len (n-1) + 1
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j],
                        dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1]);
                }
            }
        }
        return dp[1][n];
    }
};