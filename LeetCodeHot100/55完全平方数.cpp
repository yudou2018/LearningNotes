/*
* 题目：给定数字n找若干平方数1、4、9、...
* 使之和为n而平方数个数最少
*/

/*
* 方法1：动态规划
* dp[1]=dp[0]+1=1
* dp[2]=dp[2-1*1]+1=dp[1]+1=2
* dp[3]=dp[3-1]+1=dp[2]+1=3
* dp[4]=min(dp[4-1]+1,dp[4-2*2]+1)=min(dp[3]+1,dp[0]+1)=min(3,1)=1
*/
class Solution1 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int upper = sqrt(i);
            for (int j = 1; j <= upper; ++j) {
                dp[i] = dp[i] == 0 ? dp[i - j * j] : min(dp[i], dp[i - j * j]);
            }
            dp[i] += 1;
        }
        return dp[n];
    }
};