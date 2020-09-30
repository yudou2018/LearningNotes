/*
* ������ͬ����Ӳ��coins���ܽ��amount
* �����Ҫ���ٵ�Ӳ������
* ����coins=[1,2,5], amount=11
* ����3  (5+5+1=11)
*/

/*
* ����1����̬�滮
* dp[i][j]��ʾi��Ӳ�ҹ����ܽ��j��Ҫ������
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins)
            for (int i = coin; i <= amount; ++i) // i�������amount��
                dp[i] = min(dp[i], dp[i - coin] + 1); 

        return dp[amount] >= amount + 1 ? -1 : dp[amount];
    }
};