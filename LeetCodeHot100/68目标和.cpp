/*
* ��Ŀ���������� ÿ������ѡ������
* �������ΪS�������Ŀ
*/

/*
* ����1����Ŀ�޶����ֲ�����20��
* ��ʹ��dfs�ݹ��� ʱ�临�Ӷ�O(2^n)
* ÿ���ж��Ƿ��Ѿ�������ȫ��Ԫ�� �ǵĻ����ж�sum�Ƿ����S
* ��������++cnt ����������·�+��-��·
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
* ����2����̬�滮
* dp[i][j]��ʾ�����i������ʱ ��Ϊj�������Ŀ
* ����dp[i][j+nums[i]] += dp[i-1][j] 
* dp[i][j-nums[i]] += dp[i-1][j]
* ��Ϊ(j+nums[i])����(j-nums[i])���ټ���dp[i-1][j]
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
                    // ��i-1�����ֻ����� +nums[i]
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];

                    // ��i-1�����ֻ����� -nums[i]
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }

        return S > 1000 ? 0 : dp[n - 1][S + 1000];
    }
};