/*
* ��Ŀ�����������ĺ�������
* �������Ʊ�ʾ�²����λ����Ŀ
*/

/*
* ����1��λ����
* ������1���� ȡ��ĩλ ѭ��
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int ans = tmp & 1;
        tmp >>= 1;
        while (tmp) {
            ans += (tmp & 1);
            tmp >>= 1;
        }
        return ans;
    }
};

/*
* ����2����������������㷨
* ͨ��x-1�������㶼��Ϊ1 ������&����
* ÿ������һ��1
*/
class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        x ^= y;
        while (x) {
            ++ans;
            x &= (x - 1);
        }
        return ans;
    }
};