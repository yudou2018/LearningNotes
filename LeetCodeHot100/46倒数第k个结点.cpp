/*
* ��Ŀ����������ĵ�����k�����
*/

/*
* ����1��˫ָ��
* ��������ָ��ľ���Ϊk
* ��front����ĩβ��ʱ�� back���ǵ�����k��
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