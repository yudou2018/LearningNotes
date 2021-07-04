#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk; // 单调递增栈
        int n = heights.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            while(!stk.empty() && heights[i] < heights[stk.top()]) { // 因为heights[i]更小 右边界被确定
                int h = heights[stk.top()];
                while (!stk.empty() && h == heights[stk.top()]) {
                    stk.pop();
                }
                int w = stk.empty() ? i : i - stk.top() - 1;
                ans = max(ans, w * h);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int h = heights[stk.top()];
            while (!stk.empty() && h == heights[stk.top()]) {
                stk.pop();
            }
            int w = stk.empty() ? n : n - stk.top() - 1;
            ans = max(ans, w * h);
        }
        return ans;
    }
};

int main()
{
    Solution slt;
    vector<int> heights{2,1,5,6,2,3};
    cout << slt.largestRectangleArea(heights) << endl;
    return 0;
}
