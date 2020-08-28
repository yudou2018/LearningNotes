/*
* ��Ŀ��������ת
*/

/*
* ����1����ջʵ��
* �������ȫ������ջ
* Ȼ���ջʱ��������
*/
class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		ListNode* p = head;
		stack<ListNode*> stk;
		while (p) {
			stk.push(p);
			p = p->next;
		}
		ListNode* ans = stk.top();
		stk.pop();
		p = ans;
		while (stk.size()) {
			p->next = stk.top();
			stk.pop();
			p = p->next;
		}
		p->next = nullptr;
		return ans;
	}
};

/*
* ����2��������������
* �߱����߸ı�����
*/
class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr, * curr = head;
		while (curr) {
			ListNode* temp = curr->next; // �ȴ洢��һ�����
			curr->next = prev; // ����ָ��ǰ���
			prev = curr; // ǰ������Ϊ����
			curr = temp; // ����������(����洢����һ�����)
		}
		return prev; // �������ѭ��ʱcurr��nullptr ��prev����ͷ�ڵ�
	}
};

/*
* ����3���ݹ�
* �ݹ�ÿ��next�ı�
*/
class Solution3 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* p = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
};