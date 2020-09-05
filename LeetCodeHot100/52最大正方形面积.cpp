/*
* ��Ŀ����һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ������������
*/

/*
* ����1����̬�滮
* ������������matrix[i][j]Ϊ1
* ����dp[i][j]Ϊ���ϡ�������С+1
*/
class Solution1 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        int maxSide = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};