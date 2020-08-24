/*
* 题目：二维网格和一个单词找出单词是否在网格中
* 要连续 不重复的
* [["A","B","C"]
*  ["S","F","C"]
*  ["A","D","E"]]
* "ABFSA" 在
* "ABA"不在
*/


/*
* 方法1：递归回溯法
* 对每一个元素进入查看backTrace
* 若当下字符不等于单词中的对应字符 返回false
* 否则继续查看其上下左右
* 如果有一条直到索引达到最后也相等 那么整个函数返回true
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
        // 查看上下左右 后一个字符是否通
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