/*
* ���������ʾÿ���¶�
* ���������ʾ���뵱���´����µ�����
*/

/*
* ����1������ջ
* ջ��ʱ���ߵ����¶Ȳ�����ջ��ʱ ��ջ
* ����һֱ��ջ�����Ӧջ���յ���������
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