/*
* ��Ŀ������һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
* 
* ����ṹ���£�
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


/*
* ����1����������ɨ������
* ��һ��ͳ������������L 
* Ҫɾ���ľ��ǵ�L-n+1 ���� 1 2 3 4 5 
* ɾ��������2�� ��������(5-2+1)=4��
* ע����������ǵ�n=Lʱ ɾ��ͷ�ڵ�
* ʱ�临�Ӷ�O(2N) ��������
* �ռ临�Ӷ�O(1) ʹ���˳���������
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
                ++cnt; // ͳ�Ƴ���
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
* ����2�������ƽ��
* ʵ���ϲ���Ҫ����Ҳ������������
* �ƽ���ʹ�ø�������ͷ�ڵ�ɾ�������
* ʱ�临�Ӷ�O(2N) ��������
* �ռ临�Ӷ�O(1) ʹ���˳���������
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int length = 0;
        ListNode* p = dummy;
        while (p) { // �����ƽ������ͳ�Ƴ���
            ++length;
            p = p->next;
        }
        length -= n;
        p = dummy;
        for (int i = 0; i < length - 1; ++i) // ��p������Ҫɾ����ǰ��һ����㴦
            p = p->next;

        // ��ɾ������ͷ���ʱ ѭ���岻ִ��
        // ��dummy->next��Ϊ��dummy->next->next ��head->next
        // ���صĲ�����head ����dummy->next
        p->next = p->next->next;
        return dummy->next; 
    }
};


/*
* ����3��˫ָ��һ�α���
* p1��p2ָ�붼��dummy��ʼ
* p1��������n�� ��p1��p2���Ϊn
* Ȼ��p1��p2ͬʱ����ֱ��p1->nextΪ�� p1�������һ�����
* ��ʱҪɾ���ľ��� p1֮ǰn���ĺ�һ����p2�ĺ�һ��
* ��p2->next=p2->next->next����
* ʱ�临�Ӷ�O(N) ����1��
* �ռ临�Ӷ�O(1) ʹ���˳���������
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy, * p2 = dummy;
        for (int i = 0; i < n; ++i) // ���Ƚ�p1��n��
            p1 = p1->next;
        while (p1->next) { // p1��p2ʼ�ձ���n�ľ���
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next; // ɾ�����һ�����ǰn���ĺ�һ�� ��p2��һ��
        return dummy->next;
    }
};