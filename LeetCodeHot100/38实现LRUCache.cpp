/*
* 题目： LRU (最近最少使用) 缓存机制
* get(key)返回关键字key对应的value
* put(key, value)设关键字key对应的value 若不存在则插入
* capacity设定后不能扩增 如果继续put 则应该删除最久没用的
*/

/*
* 方法1：unordered_map与list
* 哈希表用于记录key对应的value
* list用于记录key的最近使用情况
* 最常用的key被放入最后
*/
class LRUCache {
    unordered_map<int, int> m;
    list<int> lst;
    int cap = 0;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!m.count(key))
            return -1;
        auto itr = lst.begin();
        while (itr != lst.end()) {
            if (*itr == key) {
                lst.erase(itr);
                lst.push_back(key);
                break;
            }
            ++itr;
        }
        return m[key];
    }

    void put(int key, int value) {
        auto itr = lst.begin();
        while (itr != lst.end()) {
            if (*itr == key) {
                lst.erase(itr);
                lst.push_back(key);
                break;
            }
            ++itr;
        }
        if (itr == lst.end())
            lst.push_back(key);
        m[key] = value;
        if (m.size() > cap) {
            itr = lst.begin();
            m.erase(*itr);
            lst.erase(itr);
        }
    }
};