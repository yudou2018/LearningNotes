/*
* ����δ�������� �ҳ���������еĳ���
*/

/*
* ����1������������
*/
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int len = 1, maxLen = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == 0) // ������ȵ� ����
                continue;
            if (nums[i + 1] - nums[i] == 1)
                ++len;
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        return max(maxLen, len);
    }
};


/*
* ����2����ϣ��
* �Դ�ɾ���ظ����ֵĹ���
* ��ÿ���׶�����С������Ϊ��ʼ
* ������������ ����ҵ� ��++thisLength
*/
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.cbegin(), nums.cend());
        int thisNum = 0, thisLength = 1, maxLength = 1;
        for (const int& num : numSet) {
            if (!numSet.count(num - 1)) {
                thisNum = num;
                thisLength = 1;
                while (numSet.count(thisNum + 1)) {
                    ++thisNum;
                    ++thisLength;
                }
            }
            maxLength = max(maxLength, thisLength);
        }
        return maxLength;
    }
};