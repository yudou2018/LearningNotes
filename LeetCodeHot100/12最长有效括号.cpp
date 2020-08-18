/*
* ��Ŀ������һ��ֻ���� '(' �� ')' ���ַ������ҳ���İ�����Ч���ŵ��Ӵ��ĳ��ȡ�
* "(()" ����2 ���Ч�����Ӵ�Ϊ "()"
* ")()())" ����4 ���Ч�����Ӵ�Ϊ "()()"
*/

/*
* ����1��������
* ��ÿ��λ�ÿ�ʼ�����������Ƿ���balance==0
* һ������balance==0 �Ƚ�һ��
* һ������balance<0˵����ʱ�����Ŷ��� ������Ч thisLength,balance����
* O(N^2) ��ʱ
*/

class Solution1 {
public:
    int longestValidParentheses(string s) {
        int balance = 0, maxLength = 0, thisLength = 0;
        for (int j = 0; j != s.size(); ++j) {
            balance = 0, thisLength = 0;
            for (int i = j; i != s.size(); ++i)
                if (s[i] == '(') {
                    ++balance;
                    ++thisLength;
                }
                else {
                    --balance;
                    ++thisLength;
                    if (balance == 0) {
                        maxLength = max(maxLength, thisLength);
                    }
                    else if (balance < 0) {
                        thisLength = 0;
                        balance = 0;
                    }
                }
        }
        return maxLength;
    }
};


/*
* ����2����̬�滮
* dp�����¼ÿ��')'��Ӧ����Ч����
* 
* ֻ��')'���п�����Ϊ��Ч���ŵĽ�β
* 1. ')'֮ǰ��'(' ֻ��Ҫ�����"()"֮ǰ��¼����Ч������+2���ɣ�
* 2. ')'֮ǰ��')'��鿴֮ǰ��')'��Ӧ����Ч����
*   ����������ȥ֮ǰ��')'��Ӧ����Ч���ȼ�1���Ӧ�������'('
*   ˵�����������"( (..��Ч..) )"һ�������ڰ���һ����Ч����
*   ������dp[i-1]+2 ��Ҫ������������"( (..��Ч..) )"֮ǰ����Ч����dp[i-dp[i-1]-2]
* ʱ�临�Ӷ�O(N) ֻ����һ��
* �ռ临�Ӷ�O(N) dp�����ǳ���n
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), maxLength = 0;
        if (n < 2) return 0; // ����С��2�Ŀ϶�������
        vector<int> dp(n, 0);
        if (s[1] == ')' && s[0] == '(') dp[1] = 2, maxLength = 2; // ��ʼ����"()" ��¼��
        for (int i = 2; i != n; ++i)
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = dp[i - 2] + 2; // ��ǰ������"()"����֮ǰ�Ļ�����+2
                maxLength = max(maxLength, dp[i]);
            }
            else if (s[i] == ')' && s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                // ��ǰ��"))" ����ǰһ��)�Ƿ���Ч���
                // ���û�� �� i-dp[i-1]-1 = i-0-1 = i-1 ��Ȼs[i-1]��')'�������ж�����
                // �������� ��ôi-dp[i-1]-1ǡ����ǰһ��')'��Ե�����֮ǰһ�� ���ǡ������'('
                // ��ô������ "( (..��Ч..) )"dp[i]=dp[i-1]+2 
                // �������i-dp[i-1]-2��Ч�Ļ� ��Ҫ��������"( (..��Ч..) )"֮ǰ��dp[i-dp[i-1]-2]
                if (i - dp[i - 1] - 2 >= 0) dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
                else dp[i] = 2 + dp[i - 1];
                maxLength = max(maxLength, dp[i]);
            }
        return maxLength;
    }
};