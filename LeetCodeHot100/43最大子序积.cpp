/*
* 题目：给定一个序列 求子序列中的最大积
*/

/*
* 方法1：动态规划数组
* 由于乘积可能出现负负得正的情况因此需要多维护一个minAns数组
* 该数组取每一步中积最小的存入
* 最后在maxAns中遍历找到最大值 利用max_element方法直接找到其对应迭代器
*/
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxAns(nums), minAns(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxAns[i] = max(maxAns[i - 1] * nums[i], max(nums[i], minAns[i - 1] * nums[i]));
            minAns[i] = min(minAns[i - 1] * nums[i], min(nums[i], maxAns[i - 1] * nums[i]));
        }
        return *max_element(maxAns.begin(), maxAns.end());
    }
};

/*
* 方法2：动态规划空间优化
* 用四个变量代替vector保存每一步的max, min
*/
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int lastMax = nums[0], lastMin = nums[0];
        int ans = max(lastMax, lastMin);
        for (int i = 1; i < nums.size(); ++i) {
            int tmpMax = max(nums[i], max(lastMax * nums[i], lastMin * nums[i]));
            int tmpMin = min(nums[i], min(lastMax * nums[i], lastMin * nums[i]));
            ans = max(tmpMax, ans); // 使用tmpMax与tmpMin

            // 用过tmpMin与tmpMax之后 赋值给lastMin lastMax
            lastMin = tmpMin; 
            lastMax = tmpMax;
        }
        return ans;
    }
};