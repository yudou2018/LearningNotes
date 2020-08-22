/*
* ��Ŀ���� word1 ת���� word2 ��ʹ�õ����ٲ�����
* ���롢ɾ�����滻
*/

/*
* ����1����̬�滮
* ��¼D[i][j]��ʾword1ǰi�� ת���� word2ǰj����Ҫ�Ĳ�����
* ��ȻD[0][j]��Ҫ��word1����j�� D[i][0]��Ҫ��word1ɾ��i��
* �������������horse, ros
* D[1][1]�Ƚϵ���h, r ��D[1][1]�Ļ������滻 +1
* D[1][2]�Ƚ�h, ro ��D[1][1]�Ļ���(1���滻)�ϲ��� +1 
* D[1][3]�Ƚ�h, ros ��D[1][2]�Ļ���(1���滻+1�β���)�ϲ��� +1
* D[2][3]�Ƚ�ho ros ��D[1][3]�Ļ����ϲ��� +1������D[2][2]�Ļ����ϲ���...
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
                int leftDown = D[i - 1][j - 1]; // w1��ǰi-1����w2��ǰj-1������ͬ
                if (word1[i - 1] != word2[j - 1]) ++leftDown; // �����ַ���ͬ ����D[i-1][j-1]�϶�һ���滻
                D[i][j] = min(left, min(down, leftDown));
            }
        return D[m][n];
    }
};