/*
* 题目：判断链表有没有环
* 有的话 返回这个环的开始结点
*/

/*
* 方法1：哈希表
* 返回第一个重复结点
*/
class Solution1 {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> saw;
        ListNode* p = head;
        while (p) {
            if (!saw.insert(p).second)
                return p;
            p = p->next;
        }
        return nullptr;
    }
};

/*
* 方法2：Floyd算法
* 用快慢指针两次遍历
* 第一次找到重合点
* 第二次一个从头开始 一个从重合点开始
* 直到遇见就是起始点
* 原理：
* 假设慢指针走过F 则快指针走过2F
* 则2F-F=C C=F 刚好为一圈长度 此时位置h 假设起点x 则F=x+h 2F=x+C+h
* 那么慢指针再走C-h可以刚好走满一圈到达环起点 F+C-h=x+h+C-h=x+C
* 从头开始的指针走C-h = F-h 则也刚好是环起点
*/
class Solution2 {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* slow = head, * fast = head;
        while (fast && slow) {
            fast = fast->next;
            if (fast == nullptr)
                return nullptr;
            fast = fast->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast == nullptr)
            return nullptr;
        ListNode* p = head;
        while (p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};