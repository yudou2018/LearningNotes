/*
* ��Ŀ���ϲ��ص�����
* [[1,3],[2,6],[8,10],[15,18]] ��[1,3]��[2,6]�ϲ�
* �ϲ��� [[1,6],[8,10],[15,18]]
*/


/*
* ����1�������Ա�
* ������֤ÿ�������������������е�
* Ȼ��ֻ�迼���ұ߽�����Ƿ�ϲ�����
*/
class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans{ intervals[0] };
        int i = 0;
        for (int j = 1; j < intervals.size(); ++j)
            if (intervals[j][0] <= ans[i][1]) // ��ǰ��������˵�С�ڵ���ǰһ���Ҷ˵� ��Ҫ�ϲ�
                ans[i][1] = max(ans[i][1], intervals[j][1]); 
            else {
                ans.emplace_back(intervals[j]); // ����ֱ�Ӳ��� �����������
                ++i;
            }
        return ans;
    }
};