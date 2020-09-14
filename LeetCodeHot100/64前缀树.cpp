/*
* ���ڵݹ��˼�빹��ǰ׺��
* ����ʱ�Զ���ȫ�ȹ���
*/

class Trie {
private:
    Trie* next[26] = { nullptr }; // �ǿձ�ʾ��������Ӧ��Сд��ĸ����
    bool isEnd = false; // ��ʾ��ǰ����Ƿ�Ϊĩβ
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this; // �Ե��½�㿪ʼ����
        for (const auto& ch : word) {
            int w = ch - 'a';
            if (root->next[w] == nullptr)
                root->next[w] = new Trie(); // �����һ��ĸΪ�� �ڶ�Ӧλ�ù�����
            root = root->next[w]; // �������±��� ������word�ַ���
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
        return root->isEnd; // ȫ�����ǿ�ָ�� ���ص���ĩβ
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // �ҵ���ĳǰ׺��ͷ������ ʵ����ֻҪ��ǰ׺��ͷ��β�����ڼ���
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