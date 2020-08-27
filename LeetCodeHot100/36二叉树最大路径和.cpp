/*
* ��Ŀ������������ �������·����
*   -10
* 9      20
*      15   7 
* ���� 15+20+7=42
*/

/*
* ����1���ݹ�
*/
class Solution {
    int maxPathSum(TreeNode* root, int& val) {
        if (root == nullptr) return 0;
        int leftSum = max(0, maxPathSum(root->left, val));
        int rightSum = max(0, maxPathSum(root->right, val));
        int lmr = root->val + leftSum + rightSum;
        int ret = root->val + max(leftSum, rightSum);
        val = max(val, max(lmr, ret)); // ȡ�������ֵ�����val
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};