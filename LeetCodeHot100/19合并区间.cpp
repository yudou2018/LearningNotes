/*
* 题目：合并重叠区间
* [[1,3],[2,6],[8,10],[15,18]] 将[1,3]与[2,6]合并
* 合并后 [[1,6],[8,10],[15,18]]
*/


/*
* 方法1：排序后对比
* 先排序保证每个区间的左端是升序排列的
* 然后只需考虑右边界决定是否合并即可
*/
class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans{ intervals[0] };
        int i = 0;
        for (int j = 1; j < intervals.size(); ++j)
            if (intervals[j][0] <= ans[i][1]) // 当前的区间左端点小于等于前一个右端点 需要合并
                ans[i][1] = max(ans[i][1], intervals[j][1]); 
            else {
                ans.emplace_back(intervals[j]); // 否则直接插入 考察后序区间
                ++i;
            }
        return ans;
    }
};