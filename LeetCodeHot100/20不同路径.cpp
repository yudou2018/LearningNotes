/*
* ��Ŀ��������λ��m*n�������Ͻ�(0,0)Ҫǰ�����½�
* ���·����Ŀ
*/


/* 
* ����1���������(m+n-2)C(n-1)
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