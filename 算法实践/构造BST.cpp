/*
* BST ×óÐ¡ÓÒ´ó
*/

class TreeNode {
public:
	int val;
	TreeNode* left = nullptr, * right = nullptr;
	TreeNode(int d = 0) :val(d) {}
};

bool searchBST(TreeNode*& root, int key, TreeNode* f, TreeNode*& p) {
	if (root == nullptr) {
		p = f;
		return false;
	}
	if (root->val == key) {
		p = root;
		return true;
	}
	if (root->val < key)
		return searchBST(root->right, key, root, p);
	return searchBST(root->left, key, root, p);
}

bool insertBST(TreeNode*& root, int key) {
	TreeNode* p, * s;
	if (!searchBST(root, key, nullptr, p)) {
		s = new TreeNode(key);
		if (!p)
			root = s;
		else if (key < p->val)
			p->left = s;
		else
			p->right = s;
		return true;
	}
	return false;
}