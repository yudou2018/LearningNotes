#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 调用一次slt后，slt中的全局变量已经修改没有清除，要小心。

class Solution {
    vector<int> ans; // 放入所有路径中全过程最低生命
    vector<int> health; // 放入当前生命
    int DIR[5] = { 1,0,-1,0,1 }; // 在此用static constexpr 在linux上编译不通过？
    int m = 0, n = 0;
    vector<vector<int>> visited;
    void dfs(vector<vector<int>>& grid, int x, int y, int tmp) {
        if (x == m - 1 && y == n - 1) {
            int minH = *min_element(health.begin(), health.end()); // 当下到达的这个路径中的最低血量
            ans.push_back(minH);
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int xx = x + DIR[k], yy = y + DIR[k + 1];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy]) {
                visited[xx][yy] = 1;
                health.push_back(tmp + grid[xx][yy]);
                dfs(grid, xx, yy, tmp + grid[xx][yy]);
                visited[xx][yy] = 0;
                health.pop_back();
            }
        }
    }
public:
    int getMinHealth(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));
        visited[0][0] = 1;
        health.push_back(grid[0][0]);
        dfs(grid, 0, 0, grid[0][0]);
        // 找所有路径 全过程最低生命的最大值
        int bestRoadHealt = *max_element(ans.begin(), ans.end());
        return bestRoadHealt >= 0 ? 1 : -bestRoadHealt + 1;
    }
};

int main()
{
    Solution slt;
    vector<vector<int>> grid{ 
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    }; //{ {-2,-3},{-5,-10} }; { {-2,-3,3},{-5,-10,1},{10,30,-5} }
    cout << slt.getMinHealth(grid) << endl;
    // 调用一次后，slt中的全局变量已经修改没有清除，要小心。

    Solution slt2; 
    grid = { 
        {-2,-3},
        {-5,-10} 
    };
    cout << slt2.getMinHealth(grid) << endl;
   
    return 0;
}
