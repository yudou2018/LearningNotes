/*
* 题目：判断链表是否回文
* 例如1->2 不是
* 1->2->2->1 是 正反一致
*/


/*
* 方法1：借助vector
* 遍历一遍把val都放入vector
* 然后利用双指针查看是否对称
* 时间复杂度O(n)
* 空间复杂度O(n)
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

