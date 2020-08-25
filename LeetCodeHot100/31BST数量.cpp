/*
* 题目：给定1、2、3 ... n，n个有序数，求可以构成BST的数目
*/

/*
* 方法1：动态规划
* G(n)表示n个结点可构成的数量 显然G(0)=G(1)=1
* 用F(i,n)表示以i为根 n个数的BST数量 
* 左树数量是 G(i-1)，右树是G(n-i) 所以F(i,n)=G(i-1)*G(n-i)
* 则G(n)=F(1,n)+F(2,n)+...+F(n,n) 即以每个数做根的情况加起来
* 即有G(n) = G(1-1)*G(n-1) + G(2-1)*G(n-2) + ... + G(n-1)G(n-n)
*/
class Solution1 {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = G[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                G[i] += G[j - 1] * G[i - j];
        return G[n];
    }
};