/*
* ��Ŀ������һ�������ж��Ƿ���BST
* ��������С�ڵ�ǰ��㣬�����������ڵ�ǰ���
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
* ����1���ݹ��������
* ����BST����������ϸ��������
* �ȰѴ𰸴������� Ȼ���ж������Ƿ��ǵ���
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
* ����2��ջ�����������
* ����ջ �߽����������������һ�����ֵ���бȽ�
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