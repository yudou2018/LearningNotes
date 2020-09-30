/*
* ��Ŀ������һ����ͳ�������������Ϊk�ĸ���
* ��[1,1,1]
* ��[1,1] [1,1] ����2
*/

/*
* ����1��ö��
* ��������������Ȼ���ж�
*/
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k)
                    ++cnt;
            }
        }
        return cnt;
    }
};

/*
* ����2��ǰ׺��+��ϣ��
* �����vec�洢�����ӵ�i��������֮��
* ��ô vec[j]-vec[i-1] ���Ǵ�i��j��������֮��
* ÿһ�����㵽��������֮��pre������map��
* �������(pre-k)������map֮��������֮ǰ��һ����vec[i] 
* ��˵��vec[i+1]������֮�� ����k
* ִ��++cnt
*/
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, pre = 0;
        unordered_map<int, int> mp{ pair<int,int>(0,1) };
        for (const int& num : nums) {
            pre += num;
            if (mp.count(pre - k))
                cnt += mp[pre - k];
            ++mp[pre];
        }
        return cnt;
    }
};