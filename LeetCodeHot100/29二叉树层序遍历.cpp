/*
* 题目：二叉树层序遍历
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
* 方法1：借用队列实现
* 多加一个变量cnt记录当前层的数目进行存入temp数组操作
* 放完一层后将temp放入ans 并且清空temp
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> que;
        que.push(root);
        int cnt;
        while (!que.empty()) {
            cnt = que.size();
            for (int i = 0; i < cnt; ++i) {
                root = que.front(), que.pop();
                temp.push_back(root->val);
                if (root->left) que.push(root->left);
                if (root->right) que.push(root->right);
            }
            ans.emplace_back(temp);
            temp.clear();
        }
        return ans;
    }
};