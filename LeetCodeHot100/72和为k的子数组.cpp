/*
* 题目：给定一数组统计连续子数组和为k的个数
* 如[1,1,1]
* 有[1,1] [1,1] 返回2
*/

/*
* 方法1：枚举
* 算出所有子数组和然后判断
*/
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k)
                    ++cnt;
            }
        }
        return cnt;
    }
};

/*
* 方法2：前缀和+哈希表
* 如果用vec存储连续加到i的子数组之和
* 那么 vec[j]-vec[i-1] 即是从i到j的子数组之和
* 每一步计算到的子数组之和pre都存入map中
* 如果当下(pre-k)存在于map之中例如是之前的一个答案vec[i] 
* 则说明vec[i+1]至当下之和 就是k
* 执行++cnt
*/
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, pre = 0;
        unordered_map<int, int> mp{ pair<int,int>(0,1) };
        for (const int& num : nums) {
            pre += num;
            if (mp.count(pre - k))
                cnt += mp[pre - k];
            ++mp[pre];
        }
        return cnt;
    }
};