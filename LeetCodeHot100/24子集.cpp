/*
* 问题：一组不含重复元素的整数数组 nums 返回所有可能不重复子集
* 例如[1,2,3]返回[[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
*/


/*
* 方法1：回溯
* 循环调用addElement每次规定此次要加入的子集规模
* 达到要求规模时 放入ans
* 没有达到则继续加入下一个元素 递归调用addElement
*/
class Solution1 {
    vector<vector<int>> ans{};
    void addElement(vector<int>& nums, vector<int>& temp, int n, int begin) {
        if (temp.size() == n) ans.push_back(temp);
        for (int i = begin; i < nums.size(); ++i) {
            temp.push_back(nums[i]); // 从begin开始放 避免重复
            addElement(nums, temp, n, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        for (int n = 0; n <= nums.size(); ++n)
            addElement(nums, temp, n, 0);
        return ans;
    }
};