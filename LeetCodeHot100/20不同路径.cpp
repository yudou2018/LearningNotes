/*
* 题目：机器人位于m*n网格左上角(0,0)要前往右下角
* 输出路径数目
*/


/* 
* 方法1：排列组合(m+n-2)C(n-1)
*/
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int i = 2; i <= m; ++i) {
            ans *= (i + n - 2);
            ans /= i - 1;
        }
        return ans;
    }
};