/*
* ��Ŀ������һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ��
*/

/*
* ����1����ϣ��ͳ�� sort����
*/
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ��ϣ��ͳ�ƴ���
        unordered_map<int, int> m;
        for (const int& num : nums)
            ++m[num];

        // ����ϣ���pair����vec
        vector<pair<int, int>> vec;
        for (const auto& mm : m)
            vec.push_back(mm); 

        // ����pair�е�second����������
        auto func = [&](const pair<int, int>& p1, const pair<int, int>& p2)->bool {
            return p1.second <= p2.second;
        };
        sort(vec.rbegin(), vec.rend(), func); 

        // ����ߴε�k�� ��Ӧ��first��Ԫ�ر������ans
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            ans.push_back(vec[i].first); 
        return ans;
    }
};