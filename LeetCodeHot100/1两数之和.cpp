/* 
*  �������ܣ����ȱ���һ����������ַ����ϣ����
*  �ڶ��α������ң�target-nums[i]���Ƿ����
*  ������ڣ����ܹ����Լ������ж��Ƿ�m[target-nums[i]]!=i
*  ��������˵���ҵ��˽�� 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i != nums.size(); ++i)
            m[nums[i]] = i;
        for (int i = 0; i != nums.size(); ++i)
            if (m.count(target - nums[i])&&m[target-nums[i]]!=i)
                return vector<int>{i, m[target - nums[i]]};
        return {};
    }
};