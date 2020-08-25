/*
* ��Ŀ���ж�һ�������Ƿ��ǻ�������
* [3,2,0,-4] pos=1��ʾ���Ľ���nextָ������1��
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
* ����1��unordered_set���뷨
* ����������ʧ��˵�����ظ�
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
* ����2������ָ��
* һ��һ�� ����л��������
* ��ָ��һ��ǰ��������λ
* ��ָ��һ��ǰ��һ����λ
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