/*
* 题目：根据一棵树的前序遍历、后序遍历数组
* 构造这棵树
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
* 前序遍历中第一个元素就是根
* 那么在中序遍历数组中找到该根对应位置 左边就是左子树 右边就是右子树
* 递归这个过程构造整个树
*/
class Solution1 {
    unordered_map<int, int> m; // 用哈希表存储中序遍历中根的索引 便于查找

    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int pLeft, int pRight, int inLeft, int inRight) {
        if (pLeft > pRight) return nullptr;
        int pRoot = pLeft, inRoot = m[preorder[pRoot]]; // 在中序里找到根
        TreeNode* root = new TreeNode(preorder[pRoot]); // 建立根节点
        int sizeLeft = inRoot - inLeft; // 中序的根索引 减去 最左索引 得左子树长度

        // 传入在前序、中序遍历数组中 左子树与右子树索引范围 再次递归构造每个“根节点”
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