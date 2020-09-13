/*
* ��Ŀ���������������������
* ����[10,9,2,5,3,7,101,18]
* �����[2,3,7,101] ����4
*/

/*
* ����1����̬�滮
* ��dp�����¼��ͷ������λ�õ����������
* ��Ȼֻ�е�nums[j]<nums[i]ʱ�Ž��м�¼
* �ҵ�֮ǰdp���� ���¼��ǰ�nums[i]Ҳ��¼��������
* ��maxDp+1
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