/*
* ��Ŀ��������������ϲ�Ϊһ���µ� ���� ��������
* ����1->2->4, 1->3->4 ��ϳ� 1->1->2->3->4
*/

/*
* ����1������������ans
* ͨ���Ƚ�l1��l2����val�Ĵ�С
* ��ans�е���һ��������new����
*/

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ���ȿ����пձ�����
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
        while (l1 && l2) { // ����l1 l2����Ч���ܱȽ���val
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
        // �˳�ѭ��������Ϊl1����l2����һ��ʧЧ
        if (l1) p->next = l1; // �������l1����Ч �ǰ�l1ʣ�µĲ��ֶ��ӵ����
        else p->next = l2; // ������l2ʣ�µĲ���
        return ans;
    }
};


/*
* ����2������������ans
* ͨ���Ƚ�l1��l2����val�Ĵ�С
* �����ƽ��򻯱߽���� ����β�����new����
*/

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1); // �½��ƽ��
        ListNode* p = preHead; // p׷�ٵ�ǰҪ��ֵ��λ��
        while (l1 && l2) { // ѭ���жϽ���С�Ľ�㸳��������λ��
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
        if (l1) p->next = l1; // �����ʣ�µĽ��
        else p->next = l2;
        return preHead->next;
    }
};


/*
* ����3���ݹ�
* ÿ�ζ������½�С�Ľ����ʣ�²�������
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