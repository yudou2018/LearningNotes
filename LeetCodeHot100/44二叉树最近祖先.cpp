/*
* ��Ŀ���ҵ����������������������
*/

/*
* ����1�������н�������֤
* һ��ݹ�������н�� ÿ�ζԽ�����findTwo���Ƿ����p��q����
* ������ʱ
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
* ����2���ݹ��޸�
* ����findTwo��ÿ����� ֻҪ��������p��q ��������������p��q
* ��������������p��q �򷵻�true
* ���lChild&&rChild ���� rootΪp��q��������������������һ��
* ����ansΪroot˵�������� 
* �����Ǻ������ ���Ա�֤���վ�����������ȴ���ans
*/
class Solution2 {
    TreeNode* ans = nullptr;
    bool findTwo(TreeNode*& root, TreeNode*& p, TreeNode*& q) {
        if (root == nullptr) return false;
        bool lChild = findTwo(root->left, p, q); // �鿴�������Ƿ����p��q
        bool rChild = findTwo(root->right, p, q); // �鿴�������Ƿ����p��q
        if (lChild && rChild || (root == p || root == q) && (lChild || rChild)) {
            ans = root; // ���㸸�ڵ������ ����ans
        }
        return lChild || rChild || root == p || root == q; // ��������true
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findTwo(root, p, q);
        return ans;
    }
};