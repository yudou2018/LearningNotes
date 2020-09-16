/*
* �ڶ������ϴ�ҽ��� ���������������
*/

/*
* ����1����̬�滮
* ���ù�ϣ��f��ʾ��ٵ��½�� g��ʾ����ٵ���
* �������ֱ�����ڵ�root ����f[root] g[root]�нϴ���
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