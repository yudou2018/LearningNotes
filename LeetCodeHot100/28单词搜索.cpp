/*
* ��Ŀ����ά�����һ�������ҳ������Ƿ���������
* Ҫ���� ���ظ���
* [["A","B","C"]
*  ["S","F","C"]
*  ["A","D","E"]]
* "ABFSA" ��
* "ABA"����
*/


/*
* ����1���ݹ���ݷ�
* ��ÿһ��Ԫ�ؽ���鿴backTrace
* �������ַ������ڵ����еĶ�Ӧ�ַ� ����false
* ��������鿴����������
* �����һ��ֱ�������ﵽ���Ҳ��� ��ô������������true
*/
class Solution {
    bool backTrace(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        char temp = board[i][j];
        board[i][j] = 0;
        ++k;
        // �鿴�������� ��һ���ַ��Ƿ�ͨ
        if ((i > 0 && backTrace(board, word, k, i - 1, j)) ||
            i < board.size() - 1 && backTrace(board, word, k, i + 1, j) ||
            j>0 && backTrace(board, word, k, i, j - 1) ||
            j < board[0].size() - 1 && backTrace(board, word, k, i, j + 1))
            return true;
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (backTrace(board, word, 0, i, j))
                    return true;
            }
        return false;
    }
};