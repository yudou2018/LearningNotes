/*
* ��Ŀ������һ�� n �� n �Ķ�ά�����ʾһ��ͼ��
* ��ת90�� Ҫ��ԭ���㷨
* 				
* [ [1,2,3],		[ [7,4,1],
*   [4,5,6],  ===>	  [8,5,2],
*   [7,8,9] ]	      [9,6,3] ]
*/


/*
* ����1��ת��+���� ���� ����+ת��
* ��Ȼ����+ת������ʵ�� ֱ��swap���е�vector����
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // ����
        int i = 0, j = n - 1;
        while (i < j) {
            swap(matrix[i], matrix[j]);
            ++i, --j;
        }

        // ת��
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};