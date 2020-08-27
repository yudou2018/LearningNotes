/*
* ��Ŀ�� LRU (�������ʹ��) �������
* get(key)���عؼ���key��Ӧ��value
* put(key, value)��ؼ���key��Ӧ��value �������������
* capacity�趨�������� �������put ��Ӧ��ɾ�����û�õ�
*/

/*
* ����1��unordered_map��list
* ��ϣ�����ڼ�¼key��Ӧ��value
* list���ڼ�¼key�����ʹ�����
* ��õ�key���������
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