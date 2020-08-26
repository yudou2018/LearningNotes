/*
* ��Ŀ������һ������ǰ������������������
* ���������
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
* ǰ������е�һ��Ԫ�ؾ��Ǹ�
* ��ô����������������ҵ��ø���Ӧλ�� ��߾��������� �ұ߾���������
* �ݹ�������̹���������
*/
class Solution1 {
    unordered_map<int, int> m; // �ù�ϣ��洢��������и������� ���ڲ���

    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int pLeft, int pRight, int inLeft, int inRight) {
        if (pLeft > pRight) return nullptr;
        int pRoot = pLeft, inRoot = m[preorder[pRoot]]; // ���������ҵ���
        TreeNode* root = new TreeNode(preorder[pRoot]); // �������ڵ�
        int sizeLeft = inRoot - inLeft; // ����ĸ����� ��ȥ �������� ������������

        // ������ǰ��������������� ��������������������Χ �ٴεݹ鹹��ÿ�������ڵ㡱
        root->left = build(preorder, inorder, pLeft + 1, pLeft + sizeLeft, inLeft, inRoot - 1);
        root->right = build(preorder, inorder, pLeft + sizeLeft + 1, pRight, inRoot + 1, inRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            m[inorder[i]] = i;
        int n = preorder.size();
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};