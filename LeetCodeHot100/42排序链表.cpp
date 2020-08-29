/*
* ��Ŀ������������
*/

/*
* ����1������vector��sort
* �Ȱ��������ݴ浽vector�н���STL�������㷨
* ������ع�����
*/
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        vector<int> vec;
        ListNode* p = head;
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        sort(vec.begin(), vec.end());
        ListNode* ans = new ListNode(vec[0]);
        p = ans;
        for (int i = 1; i < vec.size(); ++i) {
            p->next = new ListNode(vec[i]);
            p = p->next;
        }
        return ans;
    }
};

/*
* ����2���Ľ�����1
* �����������vector дһ��lambda���ʽ����
* Ȼ���ع�ԭ���� ��������new�������ڴ�ռ�
*/
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        auto func = [&](ListNode* p1, ListNode* p2)->bool {
            return p1->val < p2->val;
        };
        vector<ListNode*> vec;
        ListNode* p = head;
        while (p) {
            vec.emplace_back(p);
            p = p->next;
        }
        sort(vec.begin(), vec.end(), func);
        head = vec[0];
        p = head;
        for (int i = 1; i < vec.size(); ++i) {
            p->next = vec[i];
            p = p->next;
        }
        p->next = nullptr;
        return head;
    }
};