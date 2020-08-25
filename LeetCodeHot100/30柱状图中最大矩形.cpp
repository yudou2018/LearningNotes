/*
* ��Ŀ������ n ���Ǹ�������ʾ��״ͼ�и������ӵĸ߶�
* ���ӱ˴����ڣ����Ϊ1�����ճ����ľ��ε�������
*/


/*
* ����1��������
* �������� ��ÿ��λ������������
* ���������Ǹ߶ȴ��ڵ��ڳ�����
* ʱ�临�Ӷ�O(n^2) �ύ��ʱ
* �ռ临�Ӷ�O(1)
*/
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxS = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int left = i, right = i;
            for (; left >= 0; --left)
                if (heights[left] < heights[i])
                    break;
            for (; right < heights.size(); ++right)
                if (heights[right] < heights[i])
                    break;
            ++left; // left�ݼ�����һ��������ĵط� Ҫ�ӻظպ������λ��
            --right; // right��������һ��������ĵط� Ҫ���ظպ������λ��
            maxS = max(maxS, heights[i] * (right - left + 1));
        }
        return maxS;
    }
};


/*
* ����2��ջ
* ��ÿ���߶���������ջ
* ֻ�е�ǰ�߶�С��ջ����Ӧ�߶�ʱ
* ��ջ �õ�ǰi��ȥ��ջ��������-1�ÿ��
* ��Ϊ���˶��Ǳ��м䰫�� �������������м�
* ������ÿ��ѭ�����ظ��˹���ֱ����ջ�����ڵ��ڵ��¸߶�
* ��β�����ڱ������ڱ߽��������
*/
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return heights[0];
        vector<int> newHeights(n + 2, 0); // �����ڱ���������
        for (int i = 0; i < n; ++i)
            newHeights[i + 1] = heights[i];
        int maxS = 0;
        stack<int> stk;
        stk.push(0); // �Ƚ��ڱ�0����
        for (int i = 1; i < n + 2; ++i) {
            // �����ǰ�߶�С��ջ��
            while (newHeights[i] < newHeights[stk.top()]) {
                int height = newHeights[stk.top()]; // ȡ��ջ���߶�
                stk.pop();

                // ������Ϊ��ջ�������뵱��֮�����
                int width = i - stk.top() - 1; 

                maxS = max(maxS, width * height);
            }

            stk.push(i); // �����ǰ�߶ȴ��ڵ���ջ�� �����
        }
        return maxS;
    }
};