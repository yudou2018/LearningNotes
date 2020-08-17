/*
* 题目：数字 n 代表生成括号的对数生成所有可能的并且 有效的 括号
* 例如n=3 生成{"((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"}
*/

/*
* 方法1：暴力法 递归生成所有情况
* 生成所有括号组合
* 通过另一个函数判断是否有效 有效则放入数组
* generateAll递归生成括号 valid检查是否当前长度达到的字符串符合
* 时间复杂度O(N*2^2N) 生成所有括号 2^2N（总长2N 每个位置可能左、右两种情况）
* 验证是否符合 遍历一遍是O(N) 而每次生成一种情况就要验证一次 所以是相乘
* 空间复杂度 O(2N)递归深度是2N
*/

class Solution1 {
    bool valid(const string& str) {
        // 符合的情况是左括号的数量永远大于等于右括号
        // 最后一定左右相等
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
        // 递归生成 回溯算法
        // 例如n=2时生成的过程如下 ((((, (((), (()(, (()), ()((, ()(), ())(, ())), )(((, ... 
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
* 方法2：回溯算法
* 每次记录左右使用情况
* 如果左右剩余个数都为0直接放入
* 否则在保证right剩余个数大于left剩余个数的情况下可以放入')'
*/

class Solution2 {
    void generate(int left, int right, string& str, vector<string>& ans) {
        // 例如n=1时
        // 先放入( 然后调用g(0,1,..) 只能放入右 再次调用g(0,0)放入答案
        // 返回后删除原来的"("的末位 变为空 此时left==right==1 
        // 无法进入下一个判断使用 generate(left, right - 1, str, ans);
        // 过程结束
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