/*
* ��Ŀ������һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
* ���ֶ�Ӧ�����ֻ��Ź������뷨����ĸ 2��Ӧabc 3��Ӧdef...
*/

/*
* ����1�������㷨�ݹ飨��ʵ����dfs��bfs��Ϊÿ��Ԫ�ض��������˲�ֹһ�Σ�
* ���ȼ�¼�±����µĺ��� �浽dctnry��
* dfs����������е��������������ַ���
* ���ȴ���մ� ��i+1��temp+touch[i][j]����dfs
* ֱ�������iָʾԽ�� ����temp
* �ݹ��Զ�������֮ǰ��״̬temp��û�м���touch[i][j]��״̬
* ��ʱ����ѭ�� ������һ��
* ʱ�临�Ӷ�O(3^N*4^M) �������
* �ռ临�Ӷ�O(3^N*4^M) ��Ҫ����3^N*4^M�����
*/

class Solution {
    vector<string> ans;
    vector<vector<char>> dctnry{ {'!'},{'!'},{'a','b','c'},{'d','e','f'},{'g','h','i'},
            {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
    void dfs(vector<vector<char>>& touch, int i,string temp) {
        if (i == touch.size()) { // ���iָʾԽ�� ���봫���temp
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < touch[i].size(); ++j) { // ѭ������temp�Ӳ�ͬ�ַ�
            dfs(touch, i + 1, temp + touch[i][j]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // ���digits�ǿյ� ����Ҫ�󷵻ص���{}����{""}
        vector<vector<char>> touch;
        for (int i = 0; i < digits.size(); ++i)
            touch.push_back(dctnry[digits[i] - '0']);
        dfs(touch, 0, "");
        return ans;
    }
};