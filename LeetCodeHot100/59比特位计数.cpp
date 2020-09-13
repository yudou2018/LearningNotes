/*
* ��Ŀ������num ����0<=i<=num��Χ��ÿ��i����������Ӧ��1�ĸ���
*/

/*
* ����1������+��λ
*/
class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            int cnt = 0;
            int n = i;
            // ��λ�����Ҳ��1
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
* ����2����̬�滮 �����Чλ
* ����0 0+1 0+2 1+2 0+2^2 1+2^2 2+2^2 3+2^2...
*     0  1   2   3   4      5      6    7  ...
* ���Ǳ�ǰһ�����ֶ���һ��1 ��˿�����2^mΪ�����̬�滮
* ִ��ans[i+b]=ans[i]+1
* i<b ��Ϊ�˱����ظ�����
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