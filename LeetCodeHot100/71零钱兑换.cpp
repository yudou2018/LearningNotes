/*
* 给定不同面额的硬币coins和总金额amount
* 输出需要最少的硬币数量
* 例如coins=[1,2,5], amount=11
* 返回3  (5+5+1=11)
*/

/*
* 方法1：动态规划
* dp[i][j]表示i种硬币构成总金额j需要的数量
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins)
            for (int i = coin; i <= amount; ++i) // i上限最多amount种
                dp[i] = min(dp[i], dp[i - coin] + 1); 

        return dp[amount] >= amount + 1 ? -1 : dp[amount];
    }
};