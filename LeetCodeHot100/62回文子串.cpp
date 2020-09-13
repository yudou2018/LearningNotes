/*
* ����һ���ַ��� ������ٸ������Ӵ�
* ����"abc" ��3�� "a" "b" "c"
* "aaa"��6�� "a" "a" "a" "aa" "aa" "aaa"
*/

/*
* ����1��������չ
* ��ÿ��λ�ÿ�ʼ������չ�ȶ��Ƿ���Ĵ�
*/
class Solution1 {
    int cnt = 0;
    void helper(const string& s, int left, int right) {
        while (left >= 0 && left < s.length() && s[left] == s[right]) {
            ++cnt;
            --left;
            ++right;
        }
    }
public:
    int countSubstrings(string s) {
        if (s.length() == 0) return 0;
        for (int i = 0; i < s.length(); ++i) {
            helper(s, i, i); // ���Ĵ�����Ϊ���� �м�ֻ��һ���ַ�
            helper(s, i, i + 1); // ���Ĵ�����Ϊż�� �м��������ַ�
        }
        return cnt;
    }
};