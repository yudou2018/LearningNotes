/*
* 题目：给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
* 计算按此排列的柱子，下雨之后能接多少雨水。
*  [0,1,0,2,1,0,1,3,2,1,2,1] 放6个单位的水 图中"H"表示砖头 "="表示水
*			    H
*	    H = = = H H = H
* __H = H H = H H H H H H
*/

/*
* 方法1：三次遍历
* 第一次遍历 找到当前位置i往左看的最高峰
* 第二次遍历 找到当前位置i往右看的最高峰
* 
* 第三次遍历 两个最高峰中的最小值 减去当前i的高度 
* 就是当前竖直方向上能放的最多水
* 时间复杂度O(3N) 遍历三遍
* 空间复杂度O(2N) 用了两个数组存最高峰
*/

class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaxs(n, 0), rightMaxs(n, 0);

        // 找往左看的最高峰
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (height[i] > max) max = height[i];
            leftMaxs[i] = max;
        }

        // 找往右看的最高峰
        max = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (height[i] > max) max = height[i];
            rightMaxs[i] = max;
        }

        // 计算每个格子竖直方向上最高的水柱
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += min(leftMaxs[i], rightMaxs[i]) - height[i];

        return ans;
    }
};


/*
* 方法2：栈
* 借用栈来存储柱子的索引
* 每当遇到一个更高的柱子
* 循环比较是否高于栈顶的柱子 即还未计算的距离最近的左边柱子
* 就把栈顶取出 计算水的截面积 加入答案
* 然后还要把当下柱子放入栈
*/

class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int i = 0, ans = 0;
        while (i < height.size()) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top(); // 该top记录的是当下前一位的较低索引
                stk.pop(); // pop之后 栈的顶部是前一个柱子了
                if (stk.empty()) break; // 若低洼前面没有柱子了break
                int width = i - stk.top() - 1; // 计算两柱子间宽度

                // 取两柱子较矮的作为高
                int boundHeight = min(height[i], height[stk.top()]) - height[top];

                ans += boundHeight * width;
            }
            stk.push(i++); // 栈内放的是下标
        }
        return ans;
    }
};

/*
* 方法3：双指针
* 由方法1改进而来 从左右往中间遍历
* 右边大于左边时 左侧最大高度是限制
* 左边大于右边时 右边最大高度是限制
* 对于每个位置 求出其竖直方向上的水量
*/

class Solution3 {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0, leftMax = 0, rightMax = 0;
        while (i < j)
            if (height[i] < height[j]) {
                // 左低 如果当下是更高一个柱子 更新leftMax
                // 否则当下最高水就是leftMax-height[i]
                if (height[i] > leftMax)
                    leftMax = height[i];
                else
                    ans += leftMax - height[i];
                ++i;
            }
            else {
                // 右低 如果当下是更高一个柱子 更新rightMax
                // 否则当下最高水就是rightMax-height[j]
                if (height[j] > rightMax)
                    rightMax = height[j];
                else
                    ans += rightMax - height[j];
                --j;
            }
        return ans;
    }
};