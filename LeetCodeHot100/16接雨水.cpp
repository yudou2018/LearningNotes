/*
* ��Ŀ������ n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ��
* ���㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*  [0,1,0,2,1,0,1,3,2,1,2,1] ��6����λ��ˮ ͼ��"H"��ʾשͷ "="��ʾˮ
*			    H
*	    H = = = H H = H
* __H = H H = H H H H H H
*/

/*
* ����1�����α���
* ��һ�α��� �ҵ���ǰλ��i���󿴵���߷�
* �ڶ��α��� �ҵ���ǰλ��i���ҿ�����߷�
* 
* �����α��� ������߷��е���Сֵ ��ȥ��ǰi�ĸ߶� 
* ���ǵ�ǰ��ֱ�������ܷŵ����ˮ
* ʱ�临�Ӷ�O(3N) ��������
* �ռ临�Ӷ�O(2N) ���������������߷�
*/

class Solution1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaxs(n, 0), rightMaxs(n, 0);

        // �����󿴵���߷�
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (height[i] > max) max = height[i];
            leftMaxs[i] = max;
        }

        // �����ҿ�����߷�
        max = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (height[i] > max) max = height[i];
            rightMaxs[i] = max;
        }

        // ����ÿ��������ֱ��������ߵ�ˮ��
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += min(leftMaxs[i], rightMaxs[i]) - height[i];

        return ans;
    }
};


/*
* ����2��ջ
* ����ջ���洢���ӵ�����
* ÿ������һ�����ߵ�����
* ѭ���Ƚ��Ƿ����ջ�������� ����δ����ľ���������������
* �Ͱ�ջ��ȡ�� ����ˮ�Ľ���� �����
* Ȼ��Ҫ�ѵ������ӷ���ջ
*/

class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int i = 0, ans = 0;
        while (i < height.size()) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top(); // ��top��¼���ǵ���ǰһλ�Ľϵ�����
                stk.pop(); // pop֮�� ջ�Ķ�����ǰһ��������
                if (stk.empty()) break; // ������ǰ��û��������break
                int width = i - stk.top() - 1; // ���������Ӽ���

                // ȡ�����ӽϰ�����Ϊ��
                int boundHeight = min(height[i], height[stk.top()]) - height[top];

                ans += boundHeight * width;
            }
            stk.push(i++); // ջ�ڷŵ����±�
        }
        return ans;
    }
};

/*
* ����3��˫ָ��
* �ɷ���1�Ľ����� ���������м����
* �ұߴ������ʱ ������߶�������
* ��ߴ����ұ�ʱ �ұ����߶�������
* ����ÿ��λ�� �������ֱ�����ϵ�ˮ��
*/

class Solution3 {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = 0, leftMax = 0, rightMax = 0;
        while (i < j)
            if (height[i] < height[j]) {
                // ��� ��������Ǹ���һ������ ����leftMax
                // ���������ˮ����leftMax-height[i]
                if (height[i] > leftMax)
                    leftMax = height[i];
                else
                    ans += leftMax - height[i];
                ++i;
            }
            else {
                // �ҵ� ��������Ǹ���һ������ ����rightMax
                // ���������ˮ����rightMax-height[j]
                if (height[j] > rightMax)
                    rightMax = height[j];
                else
                    ans += rightMax - height[j];
                --j;
            }
        return ans;
    }
};