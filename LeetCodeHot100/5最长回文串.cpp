/*
* 题目：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000
*/


/*
* 方法1：暴力法（题目限定的长度1000就暗示可以用时间复杂度较高的算法）
* 另写一函数判断当下是否回文串
* 给定左、右下标开始同时往中间遍历
* 如果出现不相等的 则返回false
* 否则遍历结束全都相等 是回文串 返回true
* 依次遍历整个字符串的所有字串 找出回文串中最大长度maxLength
* 以及对应的开始位置
* 最后再调用substr(开始位置,长度)返回该回文串
* 减少了中间多次调用substr的次数 提高效率
* 时间复杂度O(N^3) 取字串O(N^2)乘以判断回文O(N)
* 空间复杂度O(1) 只使用了常数个变量
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
        if (s.size() < 2) return s; // 首先处理特殊情况
        int begin = 0, maxLength = 1;
        for (int i = 0; i < s.size() - 1; ++i)
            for (int j = i + 1; j < s.size(); ++j)
                if (j - i + 1 > maxLength && isPalindrome(s, i, j)) { 
                    // 当下长度大于maxLength且是回文串
                    // 更新长度和begin下标
                    maxLength = j - i + 1;
                    begin = i;
                }
        return s.substr(begin, maxLength);
    }
};


/*
* 方法2：中间查找法
* 修改判断回文串的方法从中间开始往两边判断
* 在遍历的每一步中从s[i]开始向两边展开 判断回文
* 一旦发现破坏了回文规则 则返回最后是回文的那个长度
* 根据回文串可能是奇数长度、偶数长度分别处理 aba abba
* 找到最长的对应的下标和长度
* 最后调用substr(开始下标,长度)返回答案
* 时间复杂度O(N^2) 因为只遍历一次 没有每次取子串 而是每次从i开始往两边判断
* 空间复杂度O(1) 只使用了常数个变量
*/

class Solution2 {
    int palindromeLength(const string& s, int i, int j) {
        while (i >= 0 && j < s.size()) {
            if (s[i] != s[j]) 
                return j - i - 1; // 例如 dabac到了i=0 j=4时 返回aba长度3
            --i, ++j;
        }
        return j - i - 1; // 有一端到头了同样返回长度
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int maxLength = 1, begin = 0;
        for (int i = 1; i < s.size(); ++i) {
            // 分别记录奇、偶长度情况的字串长度
            int evenLength = palindromeLength(s, i - 1, i); // 为最后方便计算begin 取(i-1)和i
            int oddLength = palindromeLength(s, i, i); 

            if (max(evenLength, oddLength) > maxLength) {
                maxLength = max(evenLength, oddLength);
                begin = i - maxLength / 2; // abba 对应i=2时 返回4最大 此时起始应该是a对应 i-4/2=0
                // abcba 对应i=2时候返回5最大 此时起始位置是i-5/2=i-2=0
            }
        }
        return s.substr(begin, maxLength);
    }
};


/*
* 方法3：动态规划
* 回文子串的特性 左右两端相等时 只要中间是回文的 那么它就是回文的
* dp[i][j]表示s[i,...,j]是回文 
* 则状态方程是 dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]
* 边界条件 (j-1)-(i+1)+1 < 2 下标相减+1得区间长度 
* 如果长度小于2 则d[i+1][j-1]无意义 上式子整理得 j-i<3
* 即j-i<3时 无需检查是否是回文 此时字串是一个字符
* 例如考虑s[1,...,4]是否是回文时 只需要当下s[1]==s[4]且dp[2][3]为true即可
* 观察表格 利用是dp[1][4]左下方的值 
* 为保证左下方始终有效 选择一列一列填写dp表格
* 该方法每一步计算尽可能利用了之前的结果 空间换时间
* 时间复杂度O(n^2) 选子串
* 空间复杂度O(n^2) 利用dp二维数组
*/

class Solution3 {
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int begin = 0, maxLength = 1;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true)); // 初始化dp为全true
        for (int j = 1; j < n; ++j)
            for (int i = 0; i < j; ++i) // j始终保证在i右侧
                if (s[i] != s[j]) 
                    dp[i][j] = false; // 两端不等 直接标记false
                else {
                    if (j - i < 3) 
                        dp[i][j] = true; // 两端相等且中间只有小于等于1个字符
                    else 
                        dp[i][j] = dp[i + 1][j - 1]; // 中间字符大于1个 由中间是否是回文决定

                    if (dp[i][j] && j - i + 1 > maxLength) { 
                        // dp[i][j]为true说明当下是回文串 j-i+1更大 才更新begin
                        maxLength = j - i + 1;
                        begin = i;
                    }
                }
        return s.substr(begin, maxLength);
    }
};

/*
* 方法4：Manacher算法 专门查找最长回文串的方法
* 绝大多数笔试面试中不要求掌握
*/