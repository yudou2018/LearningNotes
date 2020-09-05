/*
* 题目：给定1到n数字 n+1个 其中只有一个数字重复，找出这个数字
*/

/*
* 方法1：快慢指针
* 类似链表找环的起点
* 2L=L+C 其中L是慢指针走的长度 C为环周长
* L=x+y=C x是起点位置 y为环内相遇位置
* 将慢指针放回原点开始同步1单位速度 当与两个指针相遇时
* fast走过C-y恰好回到环起始点 而此时slow走过C-y=x也到达起始点
*/
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        // 第一次找到在环内相遇的位置
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // 慢指针放回原处 然后两个指针同时开始1单位速度前进直至相遇
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};