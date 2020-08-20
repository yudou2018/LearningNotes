/*
* ���⣺��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
* ���� ["eat", "tea", "tan", "ate", "nat", "bat"]
* ��� [
*  ["ate","eat","tea"],
*  ["nat","tan"],
*  ["bat"]
* ]
*/


/*
* ����1����ϣ��
* ���ù�ϣ��洢ÿ�������ĵ�����ͬ������
* Ȼ�������ϣ��ÿ������������ans
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ���ù�ϣ��洢�������ͬ���ַ���������
        unordered_map<string, vector<int>> siMap;
        string str;
        for (int i = 0; i < strs.size(); ++i) {
            str = strs[i];
            sort(str.begin(), str.end());
            siMap[str].push_back(i);
        }

        // ��ʼ����Ϊans(n,{}) n��������Ŀ
        vector<vector<string>> ans(siMap.size(), vector<string>{});
        int i = 0;
        for (auto sim : siMap) {
            for (int j = 0; j < sim.second.size(); ++j)
                ans[i].emplace_back(strs[sim.second[j]]); // ����������������ַ�������ans��Ӧ��
            ++i;
        }

        return ans;
    }
};


/*
* ����2��������������
* ����aab �� aba ���ɼ�Ϊ�����ַ���cntStr 2#1#0#0#...0#
* ��cntStrΪkey��cntStr��ͬ�Ķ�Ӧ�ַ����ŵ���ϣ���һ����
* ������һ���ϣ���ַ�������ans����
*/

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<int> cnt(26, 0);
        string cntStr("");
        for (int i = 0; i < strs.size(); ++i) {
            cntStr.clear(); // cntStr��Ϊ�մ�
            cnt.assign(26, 0); // ��cnt��������ȫ����Ϊ0
            for (int j = 0; j < strs[i].size(); ++j)
                ++cnt[strs[i][j] - 'a']; // �ȼ���
            for (int j = 0; j < 26; ++j)
                cntStr += to_string(cnt[j]) + '#'; // ���ݼ�������cntStr
            m[cntStr].emplace_back(strs[i]); // ����cntStr���齫��ǰstr�����ϣ��
        }

        vector<vector<string>> ans;
        for (auto mm : m)
            ans.emplace_back(mm.second); // ������ϣ�����з����vector<string>����ans

        return ans;
    }
};