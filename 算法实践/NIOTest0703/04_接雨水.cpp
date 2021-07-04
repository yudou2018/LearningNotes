#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// LeetCode 42
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1, leftMax = 0, rightMax = 0;
        int ans = 0;
        while (i < j) {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax < rightMax) {
                ans += leftMax - height[i];
                ++i;
            }
            else {
                ans += rightMax - height[j];
                --j;
            }
        }
        return ans;
    }
};

int main()
{
    Solution slt;
    vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << slt.trap(height) << endl;

    return 0;
}
