/*
* 题目：在二维矩阵内搜索数字target
*/

/*
* 方法1：右上角移动搜索
* 因为有序排列 从左往右、从上往下都是升序
* 则从右上开始 如果比target大则往左一步
* 如果比target小则往下一步 找到则返回true
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