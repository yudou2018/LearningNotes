/*
* 基于递归的思想构建前缀树
* 搜索时自动补全等功能
*/

class Trie {
private:
    Trie* next[26] = { nullptr }; // 非空表示该索引对应的小写字母存在
    bool isEnd = false; // 表示当前结点是否为末尾
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this; // 以当下结点开始搜索
        for (const auto& ch : word) {
            int w = ch - 'a';
            if (root->next[w] == nullptr)
                root->next[w] = new Trie(); // 如果下一字母为空 在对应位置构建树
            root = root->next[w]; // 继续往下遍历 遍历完word字符串
        }
        root->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (const auto& ch : word) {
            int w = ch - 'a';
            if (root->next[w] == nullptr)
                return false;
            root = root->next[w];
        }
        return root->isEnd; // 全部都非空指针 返回到达末尾
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // 找到以某前缀开头的子树 实际上只要该前缀从头到尾都存在即可
        Trie* root = this;
        for (const auto& ch : prefix) {
            int w = ch - 'a';
            if (root->next[w] == nullptr)
                return false;
            root = root->next[w];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */