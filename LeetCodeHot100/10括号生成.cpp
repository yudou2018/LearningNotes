/*
* ��Ŀ������ n �����������ŵĶ����������п��ܵĲ��� ��Ч�� ����
* ����n=3 ����{"((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"}
*/

/*
* ����1�������� �ݹ������������
* ���������������
* ͨ����һ�������ж��Ƿ���Ч ��Ч���������
* generateAll�ݹ��������� valid����Ƿ�ǰ���ȴﵽ���ַ�������
* ʱ�临�Ӷ�O(N*2^2N) ������������ 2^2N���ܳ�2N ÿ��λ�ÿ����������������
* ��֤�Ƿ���� ����һ����O(N) ��ÿ������һ�������Ҫ��֤һ�� ���������
* �ռ临�Ӷ� O(2N)�ݹ������2N
*/

class Solution1 {
    bool valid(const string& str) {
        // ���ϵ�����������ŵ�������Զ���ڵ���������
        // ���һ���������
        int balance = 0;
        for (const char& ch : str) {
            if (ch == '(') ++balance;
            else {
                if (--balance < 0) return false;
            }
        }
        return balance == 0;
    }

    void generateAll(string& str, int n, vector<string>& ans) {
        // �ݹ����� �����㷨
        // ����n=2ʱ���ɵĹ������� ((((, (((), (()(, (()), ()((, ()(), ())(, ())), )(((, ... 
        if (str.size() == n) {
            if (valid(str)) 
                ans.push_back(str);
            return;
        }
        str += '(';
        generateAll(str, n, ans);
        str.pop_back();
        str += ')';
        generateAll(str, n, ans);
        str.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string> ans;
        generateAll(str, 2 * n, ans);
        return ans;
    }
};


/*
* ����2�������㷨
* ÿ�μ�¼����ʹ�����
* �������ʣ�������Ϊ0ֱ�ӷ���
* �����ڱ�֤rightʣ���������leftʣ�����������¿��Է���')'
*/

class Solution2 {
    void generate(int left, int right, string& str, vector<string>& ans) {
        // ����n=1ʱ
        // �ȷ���( Ȼ�����g(0,1,..) ֻ�ܷ����� �ٴε���g(0,0)�����
        // ���غ�ɾ��ԭ����"("��ĩλ ��Ϊ�� ��ʱleft==right==1 
        // �޷�������һ���ж�ʹ�� generate(left, right - 1, str, ans);
        // ���̽���
        if (left == 0 && right == 0) {
            ans.push_back(str);
            return;
        }
        if (left > 0) {
            str += '(';
            generate(left - 1, right, str, ans);
            str.erase(str.size() - 1);
        }
        if (left < right) {
            str += ')';
            generate(left, right - 1, str, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        generate(n, n, str, ans);
        return ans;
    }
};