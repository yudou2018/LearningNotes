/*
* 题目：返回链表的倒数第k个结点
*/

/*
* 方法1：双指针
* 拉开两个指针的距离为k
* 当front到达末尾的时候 back就是倒数第k个
*/
class Solution1 {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* front = head;
        while (k) {
            front = front->next;
            --k;
        }
        ListNode* back = head;
        while (front) {
            front = front->next;
            back = back->next;
        }
        return back->val;
    }
};