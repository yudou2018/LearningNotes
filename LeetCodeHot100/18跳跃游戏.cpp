/*
* ��Ŀ�������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶�
* �ж����Ƿ��ܹ��������һ��λ��
* [2,3,1,1,4] ���ǿ������� 1 ������λ�� 0 ���� λ�� 1, Ȼ���ٴ�λ�� 1 �� 3 ���������һ��λ�á�
* [3,2,1,0,4] �������������ܻᵽ������Ϊ 3 ��λ�á�����λ�õ������Ծ������ 0��
*/


/*
* ����1���Ż��Ķ�̬�滮
* ��dp�����¼��ǰλ���ܷ񱻵��� �����ǰλ�õ��ﲻ��ֱ�ӷ���false
* �Ż�֮������
* 1. ����i �� ������nums[i]�Ѿ������Խ������� ֱ�ӷ���true
* 2. ��farest������¼���¿��Ե������Զ���� 
*    ��֤��[0,farest)����true�� ��ô�Ժ�����i+nums[i]>=farest�Ž����µĸ�ֵ
*/
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int farest = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (dp[i] == false) // ����λ�õ��ﲻ��
                return false;
            if (i + nums[i] >= n - 1) // ����λ�ü�������ﵽ���
                return true;
            if (i + nums[i] >= farest) // ����λ�ü����������֮ǰ����Զ �����µĸ�ֵ
                for (; farest <= i + nums[i]; ++farest)
                    dp[farest] = true;
        }
        return dp[n - 1]; // ��󷵻��Ƿ񵽴����λ��
    }
};

/*
* ����2����һ���Ľ�
* ɾȥdp���� ֻ��farest��������
* ���farestС�ڵ������� ˵�������˵���λ�� ����false
* ���i+nums[i]>farest �������Զλ��
* ���º��farest����Ѿ��ﵽ��� �򷵻�true
*/

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farest = 0;
        for (int i = 0; i < n; ++i) {
            if (farest < i) // ����λ�õ����� ����false
                return false;
            if (i + nums[i] > farest) {
                farest = i + nums[i]; // ������Զ����λ��
                if (farest >= n - 1) // �Ѿ��ﵽ��� ����true
                    return true;
            }
        }
        return farest >= n - 1; // û��ʵ�ʱ����� ֻ��Ϊ��ͨ������
        // ��Ϊ��ѭ�������һ�ε�һ��if�ж��� farest < n-1 ?
    }
};