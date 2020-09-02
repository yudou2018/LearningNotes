/*
* 给定只包含0、1的二维矩阵
* 求由1构成的最大矩形面积
* 例如[
*  ["1","0","1","0","0"],
*  ["1","0","1","1","1"],
*  ["1","1","1","1","1"],
*  ["1","0","0","1","0"]
*  ]
* 输出6
*/

/*
* 方法1：计算每一层的条形图最大矩形面积
*/
class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int gMax = 0;
        vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                heights[i][j] = matrix[i][j] - '0';
                if (i > 0 && heights[i][j] > 0) {
                    heights[i][j] += heights[i - 1][j];
                }
            }
            int lMax = maxlRectangle(heights[i]);
            if (lMax > gMax) gMax = lMax;
        }
        return gMax;
    }

    int maxlRectangle(vector<int>& heights) {
        int size = heights.size();
        if (size == 0) return 0;
        vector<int> left(size, 0), right(size, 0);
        for (int i = 1; i < size; ++i) {
            int pos = i;
            while (pos > 0 && heights[pos - 1] >= heights[i]) {
                pos = left[pos - 1];
            }
            left[i] = pos;
        }
        right[size - 1] = size - 1;
        for (int i = size - 2; i >= 0; --i) {
            int pos = i;
            while (pos < size - 1 && heights[pos + 1] >= heights[i]) {
                pos = right[pos + 1];
            }
            right[i] = pos;
        }
        int maxRec = 0;
        for (int i = 0; i < size; ++i) {
            int res = heights[i] * (right[i] - left[i] + 1);
            if (res > maxRec) maxRec = res;
        }
        return maxRec;
    }
};