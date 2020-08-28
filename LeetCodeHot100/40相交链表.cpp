/*
* 题目：判断两个链表是否有交点
* 有的话返回交点 否则返回nullptr
*/

/*
* 方法1：哈希表
* 先把一个链表的点都放入表内
* 然后查看另一个表的结点是否都插入成功
*/
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> saw;
        ListNode* p1 = headA, * p2 = headB;
        while (p1) {
            saw.insert(p1);
            p1 = p1->next;
        }
        while (p2) {
            if (!saw.insert(p2).second)
                return p2;
            p2 = p2->next;
        }
        return nullptr;
    }
};

/*
* 方法2：交换双指针法
* p1、p2分别从headA、headB开始
* 一个到达尾端则赋值为另一个表头
* 继续遍历直到之前剩下的一个也到达尾端再次赋值
* 继续同时遍历直到两者相等 返回 
* 若两次赋值后都没有相等 说明无交点
*/
class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA, * p2 = headB;
        if (p1 == nullptr || p2 == nullptr)
            return nullptr;
        int n = 3;
        while (n) {
            while (p1 && p2) {
                if (p1 == p2)
                    return p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            if (p1 == nullptr)
                p1 = headB;
            else if (p2 == nullptr)
                p2 = headA;
            --n;
        }
        return nullptr;
    }
};