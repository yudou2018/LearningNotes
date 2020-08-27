/*
* ��Ŀ���ж�������û�л�
* �еĻ� ����������Ŀ�ʼ���
*/

/*
* ����1����ϣ��
* ���ص�һ���ظ����
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
* ����2��Floyd�㷨
* �ÿ���ָ�����α���
* ��һ���ҵ��غϵ�
* �ڶ���һ����ͷ��ʼ һ�����غϵ㿪ʼ
* ֱ������������ʼ��
* ԭ��
* ������ָ���߹�F ���ָ���߹�2F
* ��2F-F=C C=F �պ�ΪһȦ���� ��ʱλ��h �������x ��F=x+h 2F=x+C+h
* ��ô��ָ������C-h���Ըպ�����һȦ���ﻷ��� F+C-h=x+h+C-h=x+C
* ��ͷ��ʼ��ָ����C-h = F-h ��Ҳ�պ��ǻ����
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