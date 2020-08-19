/*
* 题目：给定一个 n × n 的二维矩阵表示一个图像
* 旋转90度 要求原地算法
* 				
* [ [1,2,3],		[ [7,4,1],
*   [4,5,6],  ===>	  [8,5,2],
*   [7,8,9] ]	      [9,6,3] ]
*/


/*
* 方法1：转置+换列 或者 换行+转置
* 显然换行+转置容易实现 直接swap其中的vector即可
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 换行
        int i = 0, j = n - 1;
        while (i < j) {
            swap(matrix[i], matrix[j]);
            ++i, --j;
        }

        // 转置
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};