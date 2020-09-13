/*
* ��������[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
* [h,k]��ʾ���h ǰ����k������ߴ��ڵ���h
* ��������������������
*/

/*
* ����1������������
* �ɸߵ�������� �����ͬ����k�ɵ͵�����
* Ȼ��Ӹߵ��Ͳ���people[i][1]������
* ��Ϊ��������� ���Բ���list
*/
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // ���򷽷�����������ɸߵ��� �����ͬ�� �ڶ���Ԫ����С����
        auto cmp = [&](const vector<int> a, const vector<int> b) ->bool {
            return a[0] == b[0] ? a[1] <= b[1] : a[0] > b[0];
        };
        sort(people.begin(), people.end(), cmp);
        int n = people.size();
        list<vector<int>> lst;
        for (int i = 0; i < n; ++i) {
            auto pos = lst.begin();
            advance(pos, people[i][1]); // ������������Ŀ��λ��
            lst.insert(pos, people[i]);
        }
        return vector<vector<int>>(lst.cbegin(), lst.cend());
    }
};