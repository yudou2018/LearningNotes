/*
* 题目：给定二叉树 展开为只有右子树 即链表
*/


/*
* 方法1：借助数组
* 首先先序遍历将结点都存入vector
* 然后依次赋值给root右子树
*/
class Solution1 {
    void preOrder(TreeNode*& root, vector<TreeNode*>& ndVec) {
        if (root == nullptr) return;
        ndVec.emplace_back(root);
        preOrder(root->left, ndVec);
        preOrder(root->right, ndVec);
    }
public:
    void flatten(TreeNode* root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr)
            return;
        vector<TreeNode*> ndVec;
        preOrder(root, ndVec);
        TreeNode* p = root;
        for (int i = 0; i < ndVec.size(); ++i) {
            p->left = nullptr;
            p->right = ndVec[i];
            p = p->right;
        }
    }
};