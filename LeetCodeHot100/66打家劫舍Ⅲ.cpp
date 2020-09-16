/*
* 在二叉树上打家劫舍 不能连续打劫两个
*/

/*
* 方法1：动态规划
* 利用哈希表f表示打劫当下结点 g表示不打劫当下
* 后序遍历直至根节点root 返回f[root] g[root]中较大者
*/
class Solution1 {
    unordered_map<TreeNode*, int> f, g;
    void dfs(TreeNode* o) {
        if (!o) return;
        dfs(o->left);
        dfs(o->right);
        f[o] = o->val + g[o->left] + g[o->right];
        g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
    }
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};