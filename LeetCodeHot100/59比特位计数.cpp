/*
* 题目：给定num 计算0<=i<=num范围中每个i二进制数对应的1的个数
*/

/*
* 方法1：遍历+移位
*/
class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            int cnt = 0;
            int n = i;
            // 移位计算右侧的1
            while (n) {
                if (n & 1)
                    ++cnt;
                n >>= 1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};

/*
* 方法2：动态规划 最高有效位
* 考虑0 0+1 0+2 1+2 0+2^2 1+2^2 2+2^2 3+2^2...
*     0  1   2   3   4      5      6    7  ...
* 都是比前一个数字多了一个1 因此可以以2^m为间隔动态规划
* 执行ans[i+b]=ans[i]+1
* i<b 是为了避免重复计算
*/
class Solution2 {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        int i = 0, b = 1;
        while (b <= num) {
            while (i < b && i + b <= num) {
                ans[i + b] = ans[i] + 1;
                ++i;
            }
            b <<= 1;
            i = 0;
        }
        return ans;
    }
};