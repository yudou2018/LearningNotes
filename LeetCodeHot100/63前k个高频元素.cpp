/*
* 题目：给定一个非空的整数数组，返回其中出现频率前 k 高的元素
*/

/*
* 方法1：哈希表统计 sort排序
*/
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 哈希表统计次数
        unordered_map<int, int> m;
        for (const int& num : nums)
            ++m[num];

        // 将哈希表的pair放入vec
        vector<pair<int, int>> vec;
        for (const auto& mm : m)
            vec.push_back(mm); 

        // 利用pair中的second即次数排序
        auto func = [&](const pair<int, int>& p1, const pair<int, int>& p2)->bool {
            return p1.second <= p2.second;
        };
        sort(vec.rbegin(), vec.rend(), func); 

        // 将最高次的k个 对应的first即元素本身放入ans
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            ans.push_back(vec[i].first); 
        return ans;
    }
};