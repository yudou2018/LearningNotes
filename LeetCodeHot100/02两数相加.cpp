/*
* 题目：在链表上逆序模拟两数相加
* 比如 4->5->6 + 5->2->4 实际表示654+425
*/


/* 
* 方法1：递归
* 做加法首先应该记得要有进位carry
* ①当两节点都不为空时 为ans初始化为 两个值相加并且加上carry
*   此时如果加起来是两位数 则进位继续置1 否则carry置0
* ②只有一个节点有效时 只需考虑当下节点值和进位carry 以相加
*   结果初始化 carry处理方式同上
* ③两个节点都为空时 只需考虑carry
*/

class Solution1 {
    int carry = 0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        if (l1 && l2) {
            ans = new ListNode(l1->val + l2->val + carry);
            if (ans->val > 9) {
                carry = 1;
                ans->val -= 10;
            }
            else {
                carry = 0;
            }
            ans->next = addTwoNumbers(l1->next, l2->next);
        }
        else if (l1) {
            ans = new ListNode(l1->val + carry);
            if (ans->val > 9) {
                carry = 1;
                ans->val -= 10;
            }
            else {
                carry = 0;
            }
            ans->next = addTwoNumbers(l1->next, nullptr);
        }
        else if (l2) {
            ans = new ListNode(l2->val + carry);
            if (ans->val > 9) {
                carry = 1;
                ans->val -= 10;
            }
            else {
                carry = 0;
            }
            ans->next = addTwoNumbers(l2->next, nullptr);
        }
        else if (carry) {
            ans = new ListNode(carry);
        }
        return ans;
    }
};


/*
* 方法2：迭代
* 大体思路与递归相似
* 以下优化之处在于先用变量x、y判断是否两个节点有效
* 再以sum表示两数之和 那么carry就是sum/10 放到结果中的是sum%10
*/

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* beforeAns = new ListNode(0), * p = l1, * q = l2;
        ListNode* curr = beforeAns;
        int carry = 0;
        while (p || q) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry) curr->next = new ListNode(1);
        return beforeAns->next;
    }
};