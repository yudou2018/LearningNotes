/*
* 给定数组[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
* [h,k]表示身高h 前面有k个人身高大于等于h
* 排序后数组满足这个规律
*/

/*
* 方法1：先排序后插入
* 由高到低排序后 身高相同的以k由低到高排
* 然后从高到低插入people[i][1]索引处
* 因为插入操作多 所以采用list
*/
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序方法：首先身高由高到低 身高相同的 第二个元素由小到大
        auto cmp = [&](const vector<int> a, const vector<int> b) ->bool {
            return a[0] == b[0] ? a[1] <= b[1] : a[0] > b[0];
        };
        sort(people.begin(), people.end(), cmp);
        int n = people.size();
        list<vector<int>> lst;
        for (int i = 0; i < n; ++i) {
            auto pos = lst.begin();
            advance(pos, people[i][1]); // 迭代器步进至目标位置
            lst.insert(pos, people[i]);
        }
        return vector<vector<int>>(lst.cbegin(), lst.cend());
    }
};