/*
* 题目：求数组中最长上升子序列
* 例如[10,9,2,5,3,7,101,18]
* 最长的是[2,3,7,101] 长度4
*/

/*
* 方法1：动态规划
* 以dp数组记录从头到当下位置的最长上升长度
* 显然只有当nums[j]<nums[i]时才进行记录
* 找到之前dp最大的 当下即是把nums[i]也记录到长度内
* 即maxDp+1
*/
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int maxDp = dp[i];
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i]) 
                    maxDp = max(maxDp, dp[j]);
            dp[i] = maxDp + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};