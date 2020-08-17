/*
* ��Ŀ������һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000
*/


/*
* ����1������������Ŀ�޶��ĳ���1000�Ͱ�ʾ������ʱ�临�ӶȽϸߵ��㷨��
* ��дһ�����жϵ����Ƿ���Ĵ�
* ���������±꿪ʼͬʱ���м����
* ������ֲ���ȵ� �򷵻�false
* �����������ȫ����� �ǻ��Ĵ� ����true
* ���α��������ַ����������ִ� �ҳ����Ĵ�����󳤶�maxLength
* �Լ���Ӧ�Ŀ�ʼλ��
* ����ٵ���substr(��ʼλ��,����)���ظû��Ĵ�
* �������м��ε���substr�Ĵ��� ���Ч��
* ʱ�临�Ӷ�O(N^3) ȡ�ִ�O(N^2)�����жϻ���O(N)
* �ռ临�Ӷ�O(1) ֻʹ���˳���������
*/

class Solution1 {
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s; // ���ȴ����������
        int begin = 0, maxLength = 1;
        for (int i = 0; i < s.size() - 1; ++i)
            for (int j = i + 1; j < s.size(); ++j)
                if (j - i + 1 > maxLength && isPalindrome(s, i, j)) { 
                    // ���³��ȴ���maxLength���ǻ��Ĵ�
                    // ���³��Ⱥ�begin�±�
                    maxLength = j - i + 1;
                    begin = i;
                }
        return s.substr(begin, maxLength);
    }
};


/*
* ����2���м���ҷ�
* �޸��жϻ��Ĵ��ķ������м俪ʼ�������ж�
* �ڱ�����ÿһ���д�s[i]��ʼ������չ�� �жϻ���
* һ�������ƻ��˻��Ĺ��� �򷵻�����ǻ��ĵ��Ǹ�����
* ���ݻ��Ĵ��������������ȡ�ż�����ȷֱ��� aba abba
* �ҵ���Ķ�Ӧ���±�ͳ���
* ������substr(��ʼ�±�,����)���ش�
* ʱ�临�Ӷ�O(N^2) ��Ϊֻ����һ�� û��ÿ��ȡ�Ӵ� ����ÿ�δ�i��ʼ�������ж�
* �ռ临�Ӷ�O(1) ֻʹ���˳���������
*/

class Solution2 {
    int palindromeLength(const string& s, int i, int j) {
        while (i >= 0 && j < s.size()) {
            if (s[i] != s[j]) 
                return j - i - 1; // ���� dabac����i=0 j=4ʱ ����aba����3
            --i, ++j;
        }
        return j - i - 1; // ��һ�˵�ͷ��ͬ�����س���
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int maxLength = 1, begin = 0;
        for (int i = 1; i < s.size(); ++i) {
            // �ֱ��¼�桢ż����������ִ�����
            int evenLength = palindromeLength(s, i - 1, i); // Ϊ��󷽱����begin ȡ(i-1)��i
            int oddLength = palindromeLength(s, i, i); 

            if (max(evenLength, oddLength) > maxLength) {
                maxLength = max(evenLength, oddLength);
                begin = i - maxLength / 2; // abba ��Ӧi=2ʱ ����4��� ��ʱ��ʼӦ����a��Ӧ i-4/2=0
                // abcba ��Ӧi=2ʱ�򷵻�5��� ��ʱ��ʼλ����i-5/2=i-2=0
            }
        }
        return s.substr(begin, maxLength);
    }
};


/*
* ����3����̬�滮
* �����Ӵ������� �����������ʱ ֻҪ�м��ǻ��ĵ� ��ô�����ǻ��ĵ�
* dp[i][j]��ʾs[i,...,j]�ǻ��� 
* ��״̬������ dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]
* �߽����� (j-1)-(i+1)+1 < 2 �±����+1�����䳤�� 
* �������С��2 ��d[i+1][j-1]������ ��ʽ������� j-i<3
* ��j-i<3ʱ �������Ƿ��ǻ��� ��ʱ�ִ���һ���ַ�
* ���翼��s[1,...,4]�Ƿ��ǻ���ʱ ֻ��Ҫ����s[1]==s[4]��dp[2][3]Ϊtrue����
* �۲��� ������dp[1][4]���·���ֵ 
* Ϊ��֤���·�ʼ����Ч ѡ��һ��һ����дdp���
* �÷���ÿһ�����㾡����������֮ǰ�Ľ�� �ռ任ʱ��
* ʱ�临�Ӷ�O(n^2) ѡ�Ӵ�
* �ռ临�Ӷ�O(n^2) ����dp��ά����
*/

class Solution3 {
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int begin = 0, maxLength = 1;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true)); // ��ʼ��dpΪȫtrue
        for (int j = 1; j < n; ++j)
            for (int i = 0; i < j; ++i) // jʼ�ձ�֤��i�Ҳ�
                if (s[i] != s[j]) 
                    dp[i][j] = false; // ���˲��� ֱ�ӱ��false
                else {
                    if (j - i < 3) 
                        dp[i][j] = true; // ����������м�ֻ��С�ڵ���1���ַ�
                    else 
                        dp[i][j] = dp[i + 1][j - 1]; // �м��ַ�����1�� ���м��Ƿ��ǻ��ľ���

                    if (dp[i][j] && j - i + 1 > maxLength) { 
                        // dp[i][j]Ϊtrue˵�������ǻ��Ĵ� j-i+1���� �Ÿ���begin
                        maxLength = j - i + 1;
                        begin = i;
                    }
                }
        return s.substr(begin, maxLength);
    }
};

/*
* ����4��Manacher�㷨 ר�Ų�������Ĵ��ķ���
* ����������������в�Ҫ������
*/