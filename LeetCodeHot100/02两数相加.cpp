/*
* ��Ŀ��������������ģ���������
* ���� 4->5->6 + 5->2->4 ʵ�ʱ�ʾ654+425
*/


/* 
* ����1���ݹ�
* ���ӷ�����Ӧ�üǵ�Ҫ�н�λcarry
* �ٵ����ڵ㶼��Ϊ��ʱ Ϊans��ʼ��Ϊ ����ֵ��Ӳ��Ҽ���carry
*   ��ʱ�������������λ�� ���λ������1 ����carry��0
* ��ֻ��һ���ڵ���Чʱ ֻ�迼�ǵ��½ڵ�ֵ�ͽ�λcarry �����
*   �����ʼ�� carry����ʽͬ��
* �������ڵ㶼Ϊ��ʱ ֻ�迼��carry
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
* ����2������
* ����˼·��ݹ�����
* �����Ż�֮���������ñ���x��y�ж��Ƿ������ڵ���Ч
* ����sum��ʾ����֮�� ��ôcarry����sum/10 �ŵ�����е���sum%10
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