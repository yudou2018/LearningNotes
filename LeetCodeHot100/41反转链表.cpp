/*
* 题目：将链表反转
*/

/*
* 方法1：堆栈实现
* 将结点先全部存入栈
* 然后出栈时建立链接
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
* 方法2：三变量遍历法
* 边遍历边改变链接
*/
class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr, * curr = head;
		while (curr) {
			ListNode* temp = curr->next; // 先存储下一个结点
			curr->next = prev; // 当下指向前结点
			prev = curr; // 前结点更新为当下
			curr = temp; // 当下往后走(赋其存储的下一个结点)
		}
		return prev; // 最后跳出循环时curr是nullptr 而prev则是头节点
	}
};

/*
* 方法3：递归
* 递归每个next改变
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