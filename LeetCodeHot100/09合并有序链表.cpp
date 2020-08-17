/*
* 题目：两个升序链表合并为一个新的 升序 链表并返回
* 例如1->2->4, 1->3->4 组合成 1->1->2->3->4
*/

/*
* 方法1：另设新链表ans
* 通过比较l1与l2当下val的大小
* 对ans中的下一个结点进行new创建
*/

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 首先考虑有空表的情况
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* ans;
        if (l1->val < l2->val) {
            ans = new ListNode(l1->val);
            l1 = l1->next;
        }
        else {
            ans = new ListNode(l2->val);
            l2 = l2->next;
        }
        ListNode* p = ans;
        while (l1 && l2) { // 仅当l1 l2都有效才能比较其val
            if (l1->val < l2->val) {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            p = p->next;
        }
        // 退出循环就是因为l1或者l2必有一个失效
        if (l1) p->next = l1; // 如果当下l1还有效 那把l1剩下的部分都接到最后
        else p->next = l2; // 否则后接l2剩下的部分
        return ans;
    }
};


/*
* 方法2：另设新链表ans
* 通过比较l1与l2当下val的大小
* 引入哑结点简化边界情况 但这次不适用new方法
*/

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1); // 新建哑结点
        ListNode* p = preHead; // p追踪当前要赋值的位置
        while (l1 && l2) { // 循环判断将较小的结点赋予新链表位置
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1; // 最后处理剩下的结点
        else p->next = l2;
        return preHead->next;
    }
};


/*
* 方法3：递归
* 每次都将当下较小的结点与剩下部分链接
*/

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};