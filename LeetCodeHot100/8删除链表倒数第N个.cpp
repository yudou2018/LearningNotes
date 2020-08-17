/*
* 题目：给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
* 
* 链表结构如下：
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


/*
* 方法1：借助队列扫描两遍
* 第一遍统计整个链表长度L 
* 要删除的就是第L-n+1 例如 1 2 3 4 5 
* 删除倒数第2个 则正数第(5-2+1)=4个
* 注意特殊情况是当n=L时 删除头节点
* 时间复杂度O(2N) 遍历两遍
* 空间复杂度O(1) 使用了常数个变量
*/

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        int cnt = 1;
        queue<ListNode*> que;
        ListNode* p = nullptr;
        que.push(head);
        while (!que.empty()) {
            p = que.front(), que.pop();
            if (p->next) {
                que.push(p->next);
                ++cnt; // 统计长度
            }
        }
        p = head;
        ListNode* temp;
        if (cnt == n) {
            temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        for (int i = 0; i < cnt - n - 1; ++i) {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        delete temp;
        return head;
    }
};


/*
* 方法2：借助哑结点
* 实际上不需要队列也能完成链表遍历
* 哑结点的使用更方便了头节点删除的情况
* 时间复杂度O(2N) 遍历两遍
* 空间复杂度O(1) 使用了常数个变量
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int length = 0;
        ListNode* p = dummy;
        while (p) { // 包括哑结点在内统计长度
            ++length;
            p = p->next;
        }
        length -= n;
        p = dummy;
        for (int i = 0; i < length - 1; ++i) // 将p运行至要删除的前面一个结点处
            p = p->next;

        // 当删除的是头结点时 循环体不执行
        // 则dummy->next变为了dummy->next->next 即head->next
        // 返回的不能是head 而是dummy->next
        p->next = p->next->next;
        return dummy->next; 
    }
};


/*
* 方法3：双指针一次遍历
* p1、p2指针都从dummy开始
* p1先往后走n个 则p1、p2间距为n
* 然后p1、p2同时往后直至p1->next为空 p1到达最后一个结点
* 此时要删除的就是 p1之前n个的后一个即p2的后一个
* 令p2->next=p2->next->next即可
* 时间复杂度O(N) 遍历1遍
* 空间复杂度O(1) 使用了常数个变量
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy, * p2 = dummy;
        for (int i = 0; i < n; ++i) // 首先将p1移n个
            p1 = p1->next;
        while (p1->next) { // p1与p2始终保持n的距离
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next; // 删除最后一个结点前n个的后一个 即p2后一个
        return dummy->next;
    }
};