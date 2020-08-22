/*
* 题目：将 word1 转换成 word2 所使用的最少操作数
* 插入、删除、替换
*/

/*
* 方法1：动态规划
* 记录D[i][j]表示word1前i个 转换到 word2前j个需要的操作数
* 显然D[0][j]需要给word1插入j个 D[i][0]需要给word1删除i个
* 其余情况：例如horse, ros
* D[1][1]比较的是h, r 在D[1][1]的基础上替换 +1
* D[1][2]比较h, ro 在D[1][1]的基础(1次替换)上插入 +1 
* D[1][3]比较h, ros 在D[1][2]的基础(1次替换+1次插入)上插入 +1
* D[2][3]比较ho ros 在D[1][3]的基础上插入 +1或者在D[2][2]的基础上插入...
*/
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int D[m + 1][n + 1];
        for (int i = 0; i < m + 1; ++i) D[i][0] = i;
        for (int i = 0; i < n + 1; ++i) D[0][i] = i;
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j) {
                int left = D[i][j - 1] + 1;
                int down = D[i - 1][j] + 1;
                int leftDown = D[i - 1][j - 1]; // w1的前i-1个与w2的前j-1个都相同
                if (word1[i - 1] != word2[j - 1]) ++leftDown; // 当下字符不同 则在D[i-1][j-1]上多一次替换
                D[i][j] = min(left, min(down, leftDown));
            }
        return D[m][n];
    }
};