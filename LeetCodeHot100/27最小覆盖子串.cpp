/*
* ��Ŀ���ַ���S��T��Ҫ����O(n)ʱ�临�Ӷ����ҵ�S�и���T����С�����Ӵ�
* ����S = "ADOBECODEBANC", T = "ABC"
* ���� "BANC"
*/


/*
* ����1����������
* ����unordered_map���� ��cntS�е�����t���ַ������ﵽ��С��cntTʱ
* ͳ�Ƴ��� ���С�ڵ�ǰ��С ��ô���� minLength �� range
* ������range�����Ӵ�
*/
class Solution1 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cntS, cntT;
        for (int i = 0; i < t.size(); ++i)
            ++cntT[t[i]];
        int left = 0, right = 0, minLength = INT_MAX;
        pair<int, int> range;
        s += " ";
        auto check = [&]()->bool {
            for (auto const& cT : cntT)
                if (cntS[cT.first] < cT.second)
                    return false;
            return true;
        };
        while (right < s.size()) 
            if (check()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    range = { left,right };
                }
                --cntS[s[left++]];
            }
            else
                ++cntS[s[right++]];
        
        return right == s.size() ?
            s.substr(range.first, range.second - range.first) :
            s.substr(range.first, range.second - range.first + 1);
    }
};