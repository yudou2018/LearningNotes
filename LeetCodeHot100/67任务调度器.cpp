/*
* ��Ŀ��A - Z ��ĸ��ʾ��26 �ֲ�ͬ���������
* ������ͬ���������֮������г���Ϊ n ����ȴʱ��
* �������������������Ҫ�����ʱ��
*/


class Solution1 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const char& ch : tasks)
            ++count[ch - 'A'];
        int maxCount = *max_element(count.begin(), count.end());
        size_t ans = (maxCount - 1) * (n + 1);
        ans += count_if(count.begin(), count.end(), [maxCount](int c) {return c == maxCount; });
        return max(tasks.size(), ans);
    }
};