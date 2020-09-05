/*
* ��Ŀ�������ַ���s��һ����dict
* ���Ƿ�s����ȫ������Ϊdict�е�Ԫ��
*/

/*
* ����1����̬�滮
* dp[i] ��ʾ�ַ���sǰi���ַ���ɵ��ַ����Ƿ���dict��
* ÿһ���жϴ�j��i���Ӵ��Ƿ������dict
* �������Ҵ�0������λ�õ��Ӵ�Ҳ����
* ��Ӧ��dp��Ϊtrue
*/
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        if (size == 0)
            return false;
        unordered_set<string> wordSet(wordDict.cbegin(), wordDict.cend());
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        for (int i = 1; i < size + 1; ++i)
            for (int j = 0; j < i; ++j)
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    // substre(j,i-j)��ζ�Ŵ�j��ʼ����i-j ����j��i����
                    // �ж�������ζ��s.substr(0,j), s.substr(j,i-j)���ζ���
                    // ���̬�滮
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};