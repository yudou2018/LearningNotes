/*
* 给定数组表示每日温度
* 返回数组表示距离当日下次升温的天数
*/

/*
* 方法1：单调栈
* 栈空时或者当日温度不高于栈顶时 入栈
* 否则一直出栈计算对应栈顶日的升温天数
*/
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> stk;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};