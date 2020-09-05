/*
* 题目：给定一个数组
* 返回一个数组除对应位置外其他元素的乘积
*/

/*
* 方法1：前后缀乘积法
* 正向遍历一次ans保存对应位置之前所有数乘积
* 逆向遍历一次ans乘以对应位置之后的所有数乘积 
* 此时借用一个变量posMul保存乘积 
*/
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; ++i)
            ans[i] = ans[i - 1] * nums[i - 1];
        int posMul = 1;
        for (int i = n - 2; i >= 0; --i) {
            posMul *= nums[i + 1];
            ans[i] *= proMul;
        }
        return ans;
    }
};