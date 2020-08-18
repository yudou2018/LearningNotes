/*
* 题目：合并k个升序链表
* vector包含链表结点{
*  1->4->5,
*  1->3->4,
*  2->6
* }
* 合并后的链表为1->1->2->3->4->4->5->6
*/


/*
* 方法1：逐个比较法
* 大循环while控制不断重复 依靠检查是否vector内所有都是空指针来决定是否break
* 第一个for循环将当下答案链表初始化为第一个不为空的 并用usei记录下它的索引
* 第二个循环检查是否剩下的非空结点中有比用到的更小 有则更新为它 并更新usei
* 最后将使用到的那个结点往后推一个 p往后推一个
* 方法缺点是 如果只有一个结点非常长 那么有很多多余的扫描
* 时间复杂度O(kN) N是结点总数 k是链表数目
* 空间复杂度O(1) 是调整指针完成 而不是创建新的结点
*/

class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* prehead = new ListNode(0);
        ListNode* p = prehead;
        int usei = 0;
        bool allNull = true;
        while (1) {
            allNull = true;
            for (int i = 0; i != lists.size(); ++i)
                if (lists[i] != nullptr) {
                    p->next = lists[i];
                    usei = i;
                    allNull = false;
                    break;
                }
            if (allNull) break;
            for (int i = usei; i != lists.size(); ++i)
                if (lists[i] == nullptr)
                    continue;
                else if (lists[i]->val < p->next->val) {
                    p->next = lists[i];
                    usei = i;
                }
            lists[usei] = lists[usei]->next;
            p = p->next;
        }
        return prehead->next;
    }
};


/*
* 方法2：分治
* 每次都利用子函数将vector中链表两两合并
*/

class Solution2 {
    ListNode* mergeTwo(ListNode*& lst1, ListNode*& lst2) {
        // 合并两个有序链表
        if (lst1 == nullptr) return lst2;
        if (lst2 == nullptr) return lst1;
        ListNode* preHead = new ListNode(0);
        ListNode* p = preHead;
        while (lst1 && lst2) {
            if (lst1->val < lst2->val) {
                p->next = lst1;
                lst1 = lst1->next;
            }
            else {
                p->next = lst2;
                lst2 = lst2->next;
            }
            p = p->next;
        }
        if (lst1) p->next = lst1;
        if (lst2) p->next = lst2;
        return preHead->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return {}; // 特殊情况 不然最后跳过while返回lists[0]时出错
        int interval = 1;
        // 例如有3个 0 1 2  第一次 0与1合成0  2不动  第二次 0与2合为0
        // 有4个 0、1->0  2、3->2; 0、2->0 
        while (interval < lists.size()) {
            for (int i = 0; i < lists.size(); i += interval * 2) {
                if (i + interval >= lists.size()) break;
                lists[i] = mergeTwo(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};