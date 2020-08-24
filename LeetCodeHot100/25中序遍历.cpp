/*
* ��Ŀ�������������
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
* ����1���ݹ�
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
* ����2��ջ������
*/
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while (!stk.empty() || p) {
            // ���Ȳ鿴���ֱ��û��������
            while (p) {
                stk.push(p);
                p = p->left;
            }

            // ȡ��������� ���� �ٿ�������
            p = stk.top(), stk.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};