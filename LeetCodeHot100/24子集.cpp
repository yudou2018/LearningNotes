/*
* ���⣺һ�鲻���ظ�Ԫ�ص��������� nums �������п��ܲ��ظ��Ӽ�
* ����[1,2,3]����[[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
*/


/*
* ����1������
* ѭ������addElementÿ�ι涨�˴�Ҫ������Ӽ���ģ
* �ﵽҪ���ģʱ ����ans
* û�дﵽ�����������һ��Ԫ�� �ݹ����addElement
*/
class Solution1 {
    vector<vector<int>> ans{};
    void addElement(vector<int>& nums, vector<int>& temp, int n, int begin) {
        if (temp.size() == n) ans.push_back(temp);
        for (int i = begin; i < nums.size(); ++i) {
            temp.push_back(nums[i]); // ��begin��ʼ�� �����ظ�
            addElement(nums, temp, n, i + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        for (int n = 0; n <= nums.size(); ++n)
            addElement(nums, temp, n, 0);
        return ans;
    }
};