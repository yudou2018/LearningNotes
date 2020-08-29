/*
* 题目：找到二叉树两个结点的最近祖先
*/

/*
* 方法1：对所有结点进行验证
* 一层递归遍历所有结点 每次对结点调用findTwo看是否包含p、q两个
* 方法超时
*/
class Solution1 {
    TreeNode* ans = nullptr;
    bool findTwo(TreeNode*& root, TreeNode*& p, TreeNode*& q) {
        bool fdP = false, fdQ = false;
        queue<TreeNode*> que;
        TreeNode* pointer = root;
        que.push(pointer);
        while (!que.empty()) {
            pointer = que.front(), que.pop();
            if (pointer == p) fdP = true;
            if (pointer == q) fdQ = true;
            if (pointer->left != nullptr) que.push(pointer->left);
            if (pointer->right != nullptr) que.push(pointer->right);
        }
        return fdP && fdQ;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (findTwo(root, p, q)) ans = root;
        lowestCommonAncestor(root->left, p, q);
        lowestCommonAncestor(root->right, p, q);
        return ans;
    }
};

/*
* 方法2：递归修改
* 函数findTwo对每个结点 只要其自身是p或q 或者左子树包含p或q
* 或者右子树包含p或q 则返回true
* 如果lChild&&rChild 或者 root为p或q且左子树或右子树包含一个
* 则令ans为root说明是祖先 
* 由于是后序遍历 可以保证最终就是最近的祖先存在ans
*/
class Solution2 {
    TreeNode* ans = nullptr;
    bool findTwo(TreeNode*& root, TreeNode*& p, TreeNode*& q) {
        if (root == nullptr) return false;
        bool lChild = findTwo(root->left, p, q); // 查看左子树是否包含p、q
        bool rChild = findTwo(root->right, p, q); // 查看右子树是否包含p、q
        if (lChild && rChild || (root == p || root == q) && (lChild || rChild)) {
            ans = root; // 满足父节点的条件 存入ans
        }
        return lChild || rChild || root == p || root == q; // 包含返回true
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findTwo(root, p, q);
        return ans;
    }
};