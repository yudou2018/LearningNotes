/*
* ��Ŀ���ж����������Ƿ��н���
* �еĻ����ؽ��� ���򷵻�nullptr
*/

/*
* ����1����ϣ��
* �Ȱ�һ������ĵ㶼�������
* Ȼ��鿴��һ����Ľ���Ƿ񶼲���ɹ�
*/
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> saw;
        ListNode* p1 = headA, * p2 = headB;
        while (p1) {
            saw.insert(p1);
            p1 = p1->next;
        }
        while (p2) {
            if (!saw.insert(p2).second)
                return p2;
            p2 = p2->next;
        }
        return nullptr;
    }
};

/*
* ����2������˫ָ�뷨
* p1��p2�ֱ��headA��headB��ʼ
* һ������β����ֵΪ��һ����ͷ
* ��������ֱ��֮ǰʣ�µ�һ��Ҳ����β���ٴθ�ֵ
* ����ͬʱ����ֱ��������� ���� 
* �����θ�ֵ��û����� ˵���޽���
*/
class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA, * p2 = headB;
        if (p1 == nullptr || p2 == nullptr)
            return nullptr;
        int n = 3;
        while (n) {
            while (p1 && p2) {
                if (p1 == p2)
                    return p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            if (p1 == nullptr)
                p1 = headB;
            else if (p2 == nullptr)
                p2 = headA;
            --n;
        }
        return nullptr;
    }
};