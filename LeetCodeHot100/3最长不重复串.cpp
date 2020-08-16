/*
* ��Ŀ�����ַ������ҵ�����ظ��Ĵ� �����䳤��
* ����abcdasd ����ظ�����bcdas ����Ϊ5 ����5
*/

/*
* ����1����������hashmap
* �ù�ϣ���¼ÿ���ַ���Ӧ���±�
* �Լ�һ��������¼�������
* �����Ĺ���һ�����ֵ����ַ��������ֹ�
* ����㵱�³����Ƿ񳬹�maxLength
* ���Ҹ���hashmap�м�¼���±�Ϊ����
* ������Ҫ�ǵ���ͳ��һ���Ƿ����һ���ַ���֮ǰ�ĳ��ȸ���
*/

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ciMap;
        int maxLength = 0, lastFall = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (ciMap.count(s[i])) {
                maxLength = max(maxLength, i - lastFall);
                lastFall = max(lastFall, ciMap[s[i]] + 1);
                ciMap[s[i]] = i;
            }
            else {
                ciMap[s[i]] = i;
            }
        }
        return maxLength > s.size() - lastFall ? maxLength : s.size() - lastFall;
    }
};

/*
* ����2����������vector
* ˼���뷽��1һ�� �Ż�֮������
* ������Ŀ�����ַ�����ֻ����ASCII�����е��ַ�
* ������128����С��vector����hashmap �±�ΪASCII��
* Ԫ�ش�С��¼���ֵ�λ��
* ��ѭ����Ϊ 
* ��������ַ���Ӧ��λ�ñ���ֵ��>=0����˵��֮ǰ���ֹ���
* �Ҵ��ڻ���������� ��ô����maxLength�ʹ������
* ͬ��������Ҫ�������һ���ַ���Ӧ�����
*/

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ciMap(128, -1);
        int maxLength = 0, lastFall = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (ciMap[s[i]] >= lastFall) {
                maxLength = max(maxLength, i - lastFall);
                lastFall = ciMap[s[i]] + 1;
            }
            ciMap[s[i]] = i;
        }
        return maxLength > s.size() - lastFall ? maxLength : s.size() - lastFall;
    }
};