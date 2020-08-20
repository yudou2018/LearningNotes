/*
* 题目：数组中的每个元素代表你在该位置可以跳跃的最大长度
* 判断你是否能够到达最后一个位置
* [2,3,1,1,4] 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
* [3,2,1,0,4] 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0。
*/


/*
* 方法1：优化的动态规划
* 以dp数组记录当前位置能否被到达 如果当前位置到达不了直接返回false
* 优化之处在于
* 1. 当下i 加 最大距离nums[i]已经到达或超越最后索引 直接返回true
* 2. 以farest变量记录当下可以到达的最远距离 
*    保证在[0,farest)都是true的 那么以后碰到i+nums[i]>=farest才进行新的赋值
*/
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int farest = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (dp[i] == false) // 当下位置到达不了
                return false;
            if (i + nums[i] >= n - 1) // 当下位置加最大距离达到最后
                return true;
            if (i + nums[i] >= farest) // 当下位置加最大距离大于之前的最远 进行新的赋值
                for (; farest <= i + nums[i]; ++farest)
                    dp[farest] = true;
        }
        return dp[n - 1]; // 最后返回是否到达最后位置
    }
};

/*
* 方法2：进一步改进
* 删去dp数组 只用farest变量即可
* 如果farest小于当下索引 说明到不了当下位置 返回false
* 如果i+nums[i]>farest 则更新最远位置
* 更新后的farest如果已经达到最后 则返回true
*/

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farest = 0;
        for (int i = 0; i < n; ++i) {
            if (farest < i) // 当下位置到不了 返回false
                return false;
            if (i + nums[i] > farest) {
                farest = i + nums[i]; // 更新最远到达位置
                if (farest >= n - 1) // 已经达到最后 返回true
                    return true;
            }
        }
        return farest >= n - 1; // 没有实际被用上 只是为了通过编译
        // 因为在循环的最后一次第一个if判断了 farest < n-1 ?
    }
};