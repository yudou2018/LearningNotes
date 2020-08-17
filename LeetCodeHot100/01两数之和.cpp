/* 
*  方法介绍：首先遍历一遍把所有数字放入哈希表中
*  第二次遍历查找（target-nums[i]）是否存在
*  如果存在，则不能够是自己本身判断是否m[target-nums[i]]!=i
*  都满足则说明找到了结果 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i != nums.size(); ++i)
            m[nums[i]] = i;
        for (int i = 0; i != nums.size(); ++i)
            if (m.count(target - nums[i])&&m[target-nums[i]]!=i)
                return vector<int>{i, m[target - nums[i]]};
        return {};
    }
};