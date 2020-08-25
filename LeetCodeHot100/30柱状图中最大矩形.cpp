/*
* 题目：给定 n 个非负整数表示柱状图中各个柱子的高度
* 柱子彼此相邻，宽度为1，求勾勒出来的矩形的最大面积
*/


/*
* 方法1：暴力法
* 遍历数组 从每个位置向两边延申
* 延申条件是高度大于等于出发点
* 时间复杂度O(n^2) 提交超时
* 空间复杂度O(1)
*/
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxS = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int left = i, right = i;
            for (; left >= 0; --left)
                if (heights[left] < heights[i])
                    break;
            for (; right < heights.size(); ++right)
                if (heights[right] < heights[i])
                    break;
            ++left; // left递减至第一个不满足的地方 要加回刚好满足的位置
            --right; // right递增至第一个不满足的地方 要减回刚好满足的位置
            maxS = max(maxS, heights[i] * (right - left + 1));
        }
        return maxS;
    }
};


/*
* 方法2：栈
* 将每个高度索引放入栈
* 只有当前高度小于栈顶对应高度时
* 出栈 用当前i减去新栈顶的索引-1得宽度
* 因为两端都是比中间矮的 所以最大矩形在中间
* 并且在每次循环都重复此过程直至新栈顶大于等于当下高度
* 首尾加入哨兵有助于边界情况处理
*/
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return heights[0];
        vector<int> newHeights(n + 2, 0); // 插入哨兵的新数组
        for (int i = 0; i < n; ++i)
            newHeights[i + 1] = heights[i];
        int maxS = 0;
        stack<int> stk;
        stk.push(0); // 先将哨兵0放入
        for (int i = 1; i < n + 2; ++i) {
            // 如果当前高度小于栈顶
            while (newHeights[i] < newHeights[stk.top()]) {
                int height = newHeights[stk.top()]; // 取出栈顶高度
                stk.pop();

                // 计算宽度为新栈顶索引与当下之间距离
                int width = i - stk.top() - 1; 

                maxS = max(maxS, width * height);
            }

            stk.push(i); // 如果当前高度大于等于栈顶 则放入
        }
        return maxS;
    }
};