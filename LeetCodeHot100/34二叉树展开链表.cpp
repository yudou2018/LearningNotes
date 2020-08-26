/*
* ��Ŀ������������ չ��Ϊֻ�������� ������
*/


/*
* ����1����������
* ���������������㶼����vector
* Ȼ�����θ�ֵ��root������
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