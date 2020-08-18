/*
* 题目：给定一个无重复元素的数组 candidates 和一个目标数 target ，
* 找出 candidates 中所有可以使数字和为 target 的组合。
* 组合不能重复 例如[3,2,2]和[2,3,2]和[2,2,3]应被视作一种情况
*/

/*
* 方法1：递归回溯
* 先找到所有可以的组合
* 然后只有当该组合在ans中不存在时 插入
* 判断是否重复的方法用的是排序然后线性查找比较
*/

class Solution1 {
    void sumTarget(vector<vector<int>>& ans, vector<int> temp, const vector<int>& candidates, const int target) {
        // target小于0说明已经越界 返回看下一种组合
        if (target < 0) return;
        if (target == 0) {
            // target为0说明当前temp组合以满足第一个条件
            // 排序后线性查找看是否重复
            sort(temp.begin(), temp.end());
            for (int i = 0; i < ans.size(); ++i)
                if (ans[i] == temp) return;
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            sumTarget(ans, temp, candidates, target - candidates[i]);
            temp.pop_back(); // 每次出来后删掉back重新插入新的元素
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sumTarget(ans, temp, candidates, target);
        return ans;
    }
};


/*
* 方法2：回溯递归剪枝
* 对vector排序后开始递归
* 递归时记录当下位置进入递归后只从当下位置开始继续搜索
* 如果进入下一层递归还从之前开始 那么会出现重复的组合 
*   降低了空间复杂度
* 并且由于排序后可以在当下之和已经大于target时就直接退出 
*   降低了时间复杂度
* 优化结果 
*   1084ms ==》12ms；
*   133.5MB ==》11.3MB
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    int begin = 0; // 记录当下开始的位置
    void dfs(const vector<int>& candidates, const int target) {
        if (target == 0) ans.push_back(temp);

        // 如果当下target比最开始的元素还小 那么就不应该继续往后查找了
        for (int i = begin; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            temp.push_back(candidates[i]);
            begin = i;
            dfs(candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target);
        return ans;
    }
};