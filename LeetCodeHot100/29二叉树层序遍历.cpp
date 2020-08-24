/*
* ��Ŀ���������������
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
* ����1�����ö���ʵ��
* ���һ������cnt��¼��ǰ�����Ŀ���д���temp�������
* ����һ���temp����ans �������temp
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