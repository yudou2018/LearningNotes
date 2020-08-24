/*
* 题目：给定一二叉树判断是否是BST
* 左子树都小于当前结点，右子树都大于当前结点
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*
* 方法1：递归中序遍历
* 利用BST中序遍历是严格递增数组
* 先把答案存入数组 然后判断数组是否是递增
*/
class Solution1 {
    vector<int> orderVec;
    void order(TreeNode* root) {
        if (root == nullptr)
            return;
        order(root->left);
        orderVec.push_back(root->val);
        order(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        order(root);
        if (orderVec.size() < 2) return true;
        for (int i = 0; i < orderVec.size() - 1; ++i)
            if (orderVec[i + 1] <= orderVec[i])
                return false;
        return true;
    }
};


/*
* 方法2：栈迭代中序遍历
* 利用栈 边进行中序遍历边与上一个结点值进行比较
*/
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr)
            return true;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        long long lastVal = -2147483649;
        while (!stk.empty() || p != nullptr) {
            while (p != nullptr) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top(), stk.pop();
            if (p->val <= lastVal) return false;
            lastVal = p->val;
            p = p->right;
        }
        return true;
    }
};