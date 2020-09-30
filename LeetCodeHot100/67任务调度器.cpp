/*
* 题目：A - Z 字母表示的26 种不同种类的任务
* 两个相同种类的任务之间必须有长度为 n 的冷却时间
* 计算完成所有任务所需要的最短时间
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