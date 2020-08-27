/*
* 题目：给定二叉树 返回最大路径和
*   -10
* 9      20
*      15   7 
* 返回 15+20+7=42
*/

/*
* 方法1：递归
*/
class Solution {
    int maxPathSum(TreeNode* root, int& val) {
        if (root == nullptr) return 0;
        int leftSum = max(0, maxPathSum(root->left, val));
        int rightSum = max(0, maxPathSum(root->right, val));
        int lmr = root->val + leftSum + rightSum;
        int ret = root->val + max(leftSum, rightSum);
        val = max(val, max(lmr, ret)); // 取出的最大值存放于val
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};