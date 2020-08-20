/*
* 问题：字母异位词指字母相同，但排列不同的字符串。
* 例如 ["eat", "tea", "tan", "ate", "nat", "bat"]
* 输出 [
*  ["ate","eat","tea"],
*  ["nat","tan"],
*  ["bat"]
* ]
*/


/*
* 方法1：哈希表
* 利用哈希表存储每个排序后的单词相同的索引
* 然后遍历哈希表将每组索引保存入ans
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 利用哈希表存储排序后相同的字符串的索引
        unordered_map<string, vector<int>> siMap;
        string str;
        for (int i = 0; i < strs.size(); ++i) {
            str = strs[i];
            sort(str.begin(), str.end());
            siMap[str].push_back(i);
        }

        // 初始化答案为ans(n,{}) n是种类数目
        vector<vector<string>> ans(siMap.size(), vector<string>{});
        int i = 0;
        for (auto sim : siMap) {
            for (int j = 0; j < sim.second.size(); ++j)
                ans[i].emplace_back(strs[sim.second[j]]); // 将保存的索引所对字符串放入ans对应组
            ++i;
        }

        return ans;
    }
};


/*
* 方法2：计数代替排序
* 例如aab 和 aba 都可记为计数字符串cntStr 2#1#0#0#...0#
* 以cntStr为key将cntStr相同的对应字符串放到哈希表的一组中
* 最后遍历一遍哈希表将字符串放入ans数组
*/

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<int> cnt(26, 0);
        string cntStr("");
        for (int i = 0; i < strs.size(); ++i) {
            cntStr.clear(); // cntStr置为空串
            cnt.assign(26, 0); // 将cnt数组重新全部置为0
            for (int j = 0; j < strs[i].size(); ++j)
                ++cnt[strs[i][j] - 'a']; // 先计数
            for (int j = 0; j < 26; ++j)
                cntStr += to_string(cnt[j]) + '#'; // 根据计数生成cntStr
            m[cntStr].emplace_back(strs[i]); // 根据cntStr分组将当前str放入哈希表
        }

        vector<vector<string>> ans;
        for (auto mm : m)
            ans.emplace_back(mm.second); // 遍历哈希表将所有分组的vector<string>放入ans

        return ans;
    }
};