/*
* ��Ŀ���ж������Ƿ����
* ����1->2 ����
* 1->2->2->1 �� ����һ��
*/


/*
* ����1������vector
* ����һ���val������vector
* Ȼ������˫ָ��鿴�Ƿ�Գ�
* ʱ�临�Ӷ�O(n)
* �ռ临�Ӷ�O(n)
*/
class Solution1 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* p = head;
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            if (vec[i++] != vec[j--])
                return false;
        }
        return true;
    }
};

