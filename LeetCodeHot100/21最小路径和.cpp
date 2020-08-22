/*
* ��Ŀ������һ�������Ǹ������� m x n �������ϵ����£���һ��·��ʹ��·���ϵ������ܺ�Ϊ��С
* ÿ��ֻ�����һ�����
* [[1,3,1],
*  [1,5,1],
*  [4,2,1]] �����1->3->1->1->1
*/

/*
* ����1����̬�滮
* dp(i,j)=grid(i,j)+min(dp(i+1,j),dp(i,j+1))
* ÿ�ο�����һ������С· �����������ϱ���
* �߽紦���������С ֱ�ӼӼ���
*/
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1]; // ��ʼ��dp���½�Ϊ��Ӧֵ
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                if (i + 1 < m && j + 1 < n)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]); // �Ǳ߽����
                else if (i + 1 < m)
                    dp[i][j] = grid[i][j] + dp[i + 1][j]; // j+1==n �ұ߽����
                else if (j + 1 < n)
                    dp[i][j] = grid[i][j] + dp[i][j + 1]; // i+1==m �±߽����

        return dp[0][0]; // �ҵ����ϵ����µ����·��
    }
};