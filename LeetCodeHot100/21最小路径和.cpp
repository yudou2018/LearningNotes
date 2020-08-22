/*
* 题目：给定一个包含非负整数的 m x n 网格，左上到右下，找一条路径使得路径上的数字总和为最小
* 每次只能往右或往下
* [[1,3,1],
*  [1,5,1],
*  [4,2,1]] 最短是1->3->1->1->1
*/

/*
* 方法1：动态规划
* dp(i,j)=grid(i,j)+min(dp(i+1,j),dp(i,j+1))
* 每次考虑下一步的最小路 从右下往左上遍历
* 边界处无需计算最小 直接加即可
*/
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1]; // 初始化dp右下角为对应值
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                if (i + 1 < m && j + 1 < n)
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]); // 非边界情况
                else if (i + 1 < m)
                    dp[i][j] = grid[i][j] + dp[i + 1][j]; // j+1==n 右边界情况
                else if (j + 1 < n)
                    dp[i][j] = grid[i][j] + dp[i][j + 1]; // i+1==m 下边界情况

        return dp[0][0]; // 找到左上到右下的最短路径
    }
};