/*
* ��Ŀ������1��n���� n+1�� ����ֻ��һ�������ظ����ҳ��������
*/

/*
* ����1������ָ��
* ���������һ������
* 2L=L+C ����L����ָ���ߵĳ��� CΪ���ܳ�
* L=x+y=C x�����λ�� yΪ��������λ��
* ����ָ��Ż�ԭ�㿪ʼͬ��1��λ�ٶ� ��������ָ������ʱ
* fast�߹�C-yǡ�ûص�����ʼ�� ����ʱslow�߹�C-y=xҲ������ʼ��
*/
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        // ��һ���ҵ��ڻ���������λ��
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // ��ָ��Ż�ԭ�� Ȼ������ָ��ͬʱ��ʼ1��λ�ٶ�ǰ��ֱ������
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};