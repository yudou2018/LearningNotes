/*
* ��Ŀ������һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�
* ����[1,2,3] ����[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/


/*
* ����1������
* ��vector f��¼������Щ�����Ѿ��ù�
* ������
*/

class Solution1 {
    vector<vector<int>> ans;
    vector<int> temp;
    void generate(const vector<int>& nums, vector<int>& f) {
        if (temp.size() == nums.size()) {
            // temp�����Ѿ��͸���vectorһ���������ans
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
            if (f[i] == 0) {
                // ����nums[i]���Ӧλ��1
                temp.push_back(nums[i]); 
                f[i] = 1;

                // �ݹ�
                generate(nums, f);

                // ���غ���ΪҪpop_back()ɾ��nums[i]
                // ����Ҳ��Ҫ�ѱ�־λ��λ
                f[i] = 0;
                temp.pop_back();
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> f(nums.size(), 0);
        generate(nums, f);
        return ans;
    }
};