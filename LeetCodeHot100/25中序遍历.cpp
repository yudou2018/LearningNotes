/*
* 题目：树的中序遍历
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
* 方法1：递归
*/
class Solution1 {
    vector<int> ans;
    void order(TreeNode* root) {
        if (root == nullptr) return;
        order(root->left);
        ans.push_back(root->val);
        order(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        order(root);
        return ans;
    }
};

/*
* 方法2：栈迭代法
*/
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (!stk.empty() || p) {
            // 优先查看左边直至没有左子树
            while (p) {
                stk.push(p);
                p = p->left;
            }

            // 取出最后放入的 操作 再看右子树
            p = stk.top(), stk.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};