/*
* 题目：求x的n次幂 n为任意整数
*/

/*
* 方法1：分治+递归
* 分半递归 每次n变为原来一半 递归计算
*/
class Solution1 {
    double halfPow(double x, long long n) {
        if (n == 1)
            return x;
        double half = halfPow(x, n / 2);
        if (n & 1)
            return half * half * x;

        return half * half;
    }
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1;
        if (n < 0)
            return 1 / halfPow(x, abs(n));
        return halfPow(x, n);
    }
};