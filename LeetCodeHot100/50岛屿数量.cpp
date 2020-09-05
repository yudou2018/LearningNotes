/*
* 题目 用二维矩阵1、0表示岛屿和水域
* 计算岛屿数量
*/

/*
* 方法1：深度优先搜索
* 一直遍历整个数组 遇到1则++ans
* 并且将其四邻域延申全部赋值为0
*/
class Solution1 {
    int nr = 0, nc = 0;
    void dfs(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        nr = grid.size(), nc = grid[0].size();
        int ans = 0;
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                }

        return ans;
    }
};