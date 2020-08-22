/*
* ��Ŀ���졢�ס�����0��1��2��ʾ
* ʵ�����������000...111...222...
*/

/*
* ����1������ɨ���������
* ��һ�α�������0��1��2
* �ڶ��α�����д����
*/
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = { 0 };
        for (const int& num : nums)
            ++cnt[num];
        nums.clear();
        for (int i = 0; i < 3; ++i) {
            while (cnt[i]-- > 0)
                nums.push_back(i);
        }
    }
};

/*
* ����2����ָ��һ�α���
* ��p�������� p0��¼����Ӧ�÷�0��λ�� p2��¼����Ӧ�÷�2��λ��
* ����0����p0 p��p0����1
* ����2����p2 p2�ݼ� p���� ��Ϊ�п���p2����ָ��ľ���2 ��Ҫ�ٽ���һ��
* ����������1 ֻ�����p����
*/
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int p = 0, p0 = 0, p2 = nums.size() - 1;
        while (p <= p2)
            if (nums[p] == 0)
                swap(nums[p0++], nums[p++]);
            else if (nums[p] == 2)
                swap(nums[p2--], nums[p]);
            else
                ++p;
    }
};