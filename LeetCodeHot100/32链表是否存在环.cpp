/*
* 题目：判断一个链表是否是环形链表
* [3,2,0,-4] pos=1表示最后的结点的next指向索引1处
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
* 方法1：unordered_set插入法
* 插入链表结点失败说明有重复
*/
class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        ListNode* p = head;
        while (p) {
            if (!s.insert(p).second)
                return true;
            p = p->next;
        }
        return false;
    }
};

/*
* 方法2：快慢指针
* 一快一慢 如果有环则会遇见
* 快指针一次前进两个单位
* 慢指针一次前进一个单位
*/
class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* slow = head, * fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};