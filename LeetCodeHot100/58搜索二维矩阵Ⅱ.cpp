/*
* ��Ŀ���ڶ�ά��������������target
*/

/*
* ����1�����Ͻ��ƶ�����
* ��Ϊ�������� �������ҡ��������¶�������
* ������Ͽ�ʼ �����target��������һ��
* �����targetС������һ�� �ҵ��򷵻�true
*/
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int curRow = 0, curCol = n - 1;
        while (curRow < m && curCol >= 0)
            if (matrix[curRow][curCol] < target)
                ++curRow;
            else if (matrix[curRow][curCol] > target)
                --curCol;
            else
                return true;

        return false;
    }
};