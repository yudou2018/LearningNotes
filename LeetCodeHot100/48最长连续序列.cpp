/*
* 给定未排序序列 找出最长连续序列的长度
*/

/*
* 方法1：先排序后计算
*/
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int len = 1, maxLen = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == 0) // 碰到相等的 跳过
                continue;
            if (nums[i + 1] - nums[i] == 1)
                ++len;
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        return max(maxLen, len);
    }
};


/*
* 方法2：哈希表
* 自带删除重复数字的功能
* 以每个阶段性最小数字作为开始
* 查找其递增结果 如果找到 则++thisLength
*/
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.cbegin(), nums.cend());
        int thisNum = 0, thisLength = 1, maxLength = 1;
        for (const int& num : numSet) {
            if (!numSet.count(num - 1)) {
                thisNum = num;
                thisLength = 1;
                while (numSet.count(thisNum + 1)) {
                    ++thisNum;
                    ++thisLength;
                }
            }
            maxLength = max(maxLength, thisLength);
        }
        return maxLength;
    }
};