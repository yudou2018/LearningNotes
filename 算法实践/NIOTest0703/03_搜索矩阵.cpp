#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// LeetCode 240
    // 从右上角出发 如果比target大则往左走 比target小就往下走
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (j >= 0 && i < m) {
            if (matrix[i][j] > target) {
                --j;
            }
            else if (matrix[i][j] < target) {
                ++i;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution slt;
    vector<vector<int>> matrix{ 
        {1, 4, 7, 11, 15}, 
        {2, 5, 8, 12, 19}, 
        {3, 6, 9, 16, 22}, 
        {10, 13, 14, 17, 24}, 
        {18, 21, 23, 26, 30} 
    };
    int target = 5;
    cout << slt.searchMatrix(matrix, target) << endl;

    return 0;
}
