/*
* 题目：给链表排序
*/

/*
* 方法1：借助vector和sort
* 先把链表内容存到vector中借助STL的排序算法
* 排序后重构链表
*/
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        vector<int> vec;
        ListNode* p = head;
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        sort(vec.begin(), vec.end());
        ListNode* ans = new ListNode(vec[0]);
        p = ans;
        for (int i = 1; i < vec.size(); ++i) {
            p->next = new ListNode(vec[i]);
            p = p->next;
        }
        return ans;
    }
};

/*
* 方法2：改进方法1
* 把链表结点存入vector 写一个lambda表达式排序
* 然后重构原链表 而不是用new申请新内存空间
*/
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        auto func = [&](ListNode* p1, ListNode* p2)->bool {
            return p1->val < p2->val;
        };
        vector<ListNode*> vec;
        ListNode* p = head;
        while (p) {
            vec.emplace_back(p);
            p = p->next;
        }
        sort(vec.begin(), vec.end(), func);
        head = vec[0];
        p = head;
        for (int i = 1; i < vec.size(); ++i) {
            p->next = vec[i];
            p = p->next;
        }
        p->next = nullptr;
        return head;
    }
};