/*
* ��Ŀ������ nums ��һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳ�
* ����ÿ�δ����е����ֵ
*/

/*
* ����1��������
* ÿ�����¼��㴰���е����ֵ����
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
* ����2����������
* ���õ�������ÿ�ε����ڳ��ȴﵽ��׼ʱ
* �����ans���ֵ
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
            q.push(nums[i]); // push����������бȽϹ��� ����eС�Ķ�ɾ����
            if (i - k + 1 >= 0) {
                ans.push_back(q.max()); // �����Ѿ��ﵽ��׼ �������ֵ
                if (nums[i - k + 1] == q.max())
                    q.pop(); // ������´��ڵ�һ��Ԫ�������ֵ ��Ҫ��ʽɾ�������и�Ԫ��
            }
        }
        return ans;
    }
};