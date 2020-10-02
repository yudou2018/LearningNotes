/*
* 题目：数组 nums 有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
* 返回每次窗口中的最大值
*/

/*
* 方法1：暴力法
* 每次重新计算窗口中的最大值即可
*/
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = k - 1; i < nums.size(); ++i) {
            ans.push_back(*max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
        }
        return ans;
    }
};


/*
* 方法2：单调队列
* 利用单调队列每次当窗口长度达到标准时
* 向放入ans最大值
*/
class MonotonicQueue {
public:
    void push(int e) {
        while (!data.empty() && e > data.back())
            data.pop_back();
        data.push_back(e);
    }
    void pop() {
        data.pop_front();
    }
    int max() {
        return data.front();
    }
private:
    deque<int> data;
};

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]); // push方法本身就有比较功能 将比e小的都删除掉
            if (i - k + 1 >= 0) {
                ans.push_back(q.max()); // 窗口已经达到标准 放入最大值
                if (nums[i - k + 1] == q.max())
                    q.pop(); // 如果当下窗口第一个元素是最大值 需要显式删除队列中该元素
            }
        }
        return ans;
    }
};