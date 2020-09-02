/*
* 题目：求两个数的汉宁距离
* 即二进制表示下不相等位的数目
*/

/*
* 方法1：位运算
* 异或后与1相与 取出末位 循环
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int ans = tmp & 1;
        tmp >>= 1;
        while (tmp) {
            ans += (tmp & 1);
            tmp >>= 1;
        }
        return ans;
    }
};

/*
* 方法2：布赖恩·克尼根算法
* 通过x-1将最后的零都置为1 进行与&运算
* 每次消灭一个1
*/
class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        x ^= y;
        while (x) {
            ++ans;
            x &= (x - 1);
        }
        return ans;
    }
};