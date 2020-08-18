/*
* ��Ŀ���ϲ�k����������
* vector����������{
*  1->4->5,
*  1->3->4,
*  2->6
* }
* �ϲ��������Ϊ1->1->2->3->4->4->5->6
*/


/*
* ����1������ȽϷ�
* ��ѭ��while���Ʋ����ظ� ��������Ƿ�vector�����ж��ǿ�ָ���������Ƿ�break
* ��һ��forѭ�������´������ʼ��Ϊ��һ����Ϊ�յ� ����usei��¼����������
* �ڶ���ѭ������Ƿ�ʣ�µķǿս�����б��õ��ĸ�С �������Ϊ�� ������usei
* ���ʹ�õ����Ǹ����������һ�� p������һ��
* ����ȱ���� ���ֻ��һ�����ǳ��� ��ô�кܶ�����ɨ��
* ʱ�临�Ӷ�O(kN) N�ǽ������ k��������Ŀ
* �ռ临�Ӷ�O(1) �ǵ���ָ����� �����Ǵ����µĽ��
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
* ����2������
* ÿ�ζ������Ӻ�����vector�����������ϲ�
*/

class Solution2 {
    ListNode* mergeTwo(ListNode*& lst1, ListNode*& lst2) {
        // �ϲ�������������
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
        if (lists.empty()) return {}; // ������� ��Ȼ�������while����lists[0]ʱ����
        int interval = 1;
        // ������3�� 0 1 2  ��һ�� 0��1�ϳ�0  2����  �ڶ��� 0��2��Ϊ0
        // ��4�� 0��1->0  2��3->2; 0��2->0 
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