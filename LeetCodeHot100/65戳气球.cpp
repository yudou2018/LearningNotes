/*
* ��Ŀ��������
* ������������ i ���Ϳ��Ի�� nums[left] * nums[i] * nums[right] ��Ӳ��
*/

/*
* ����1������
* �������� ���뵱��ѡ������õ���coins ά��һ�����ֵans
* ÿ��erase���ƺ�Ҫinsert�Ż�
*/
class Solution1 {
    void helper(vector<int>& nums, int coins, int& ans) {
        if (nums.size() == 0) {
            ans = max(ans, coins);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i]; //  �м�
            int delta = nums[i] * (i - 1 < 0 ? 1 : nums[i - 1]) * (i + 1 > nums.size() - 1 ? 1 : nums[i + 1]); // ����
            nums.erase(nums.begin() + i);
            helper(nums, coins + delta, ans);
            nums.insert(nums.begin() + i, tmp); // �Ż� �������������
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
* ����2����ά��̬�滮
* dp[i][j]��ʾ��i����j����������Ž�
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
* ����3����ά��̬�滮�Ż�
* dp[i][j]��ʾ��i����j����������Ž�
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