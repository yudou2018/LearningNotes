/*
* 题目：给定一个 没有重复 数字的序列，返回其所有可能的全排列。
* 例如[1,2,3] 返回[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


/*
* 方法1：回溯
* 用vector f记录当下哪些索引已经用过
* 跳过它
*/

class Solution1 {
    vector<vector<int>> ans;
    vector<int> temp;
    void generate(const vector<int>& nums, vector<int>& f) {
        if (temp.size() == nums.size()) {
            // temp长度已经和给的vector一样长则放入ans
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
            if (f[i] == 0) {
                // 放入nums[i]后对应位置1
                temp.push_back(nums[i]); 
                f[i] = 1;

                // 递归
                generate(nums, f);

                // 返回后因为要pop_back()删除nums[i]
                // 所以也需要把标志位复位
                f[i] = 0;
                temp.pop_back();
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> f(nums.size(), 0);
        generate(nums, f);
        return ans;
    }
};