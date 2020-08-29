/*
* ��Ŀ������һ������ ���������е�����
*/

/*
* ����1����̬�滮����
* ���ڳ˻����ܳ��ָ�����������������Ҫ��ά��һ��minAns����
* ������ȡÿһ���л���С�Ĵ���
* �����maxAns�б����ҵ����ֵ ����max_element����ֱ���ҵ����Ӧ������
*/
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxAns(nums), minAns(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxAns[i] = max(maxAns[i - 1] * nums[i], max(nums[i], minAns[i - 1] * nums[i]));
            minAns[i] = min(minAns[i - 1] * nums[i], min(nums[i], maxAns[i - 1] * nums[i]));
        }
        return *max_element(maxAns.begin(), maxAns.end());
    }
};

/*
* ����2����̬�滮�ռ��Ż�
* ���ĸ���������vector����ÿһ����max, min
*/
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int lastMax = nums[0], lastMin = nums[0];
        int ans = max(lastMax, lastMin);
        for (int i = 1; i < nums.size(); ++i) {
            int tmpMax = max(nums[i], max(lastMax * nums[i], lastMin * nums[i]));
            int tmpMin = min(nums[i], min(lastMax * nums[i], lastMin * nums[i]));
            ans = max(tmpMax, ans); // ʹ��tmpMax��tmpMin

            // �ù�tmpMin��tmpMax֮�� ��ֵ��lastMin lastMax
            lastMin = tmpMin; 
            lastMax = tmpMax;
        }
        return ans;
    }
};