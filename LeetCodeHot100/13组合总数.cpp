/*
* ��Ŀ������һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ��
* �ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
* ��ϲ����ظ� ����[3,2,2]��[2,3,2]��[2,2,3]Ӧ������һ�����
*/

/*
* ����1���ݹ����
* ���ҵ����п��Ե����
* Ȼ��ֻ�е��������ans�в�����ʱ ����
* �ж��Ƿ��ظ��ķ����õ�������Ȼ�����Բ��ұȽ�
*/

class Solution1 {
    void sumTarget(vector<vector<int>>& ans, vector<int> temp, const vector<int>& candidates, const int target) {
        // targetС��0˵���Ѿ�Խ�� ���ؿ���һ�����
        if (target < 0) return;
        if (target == 0) {
            // targetΪ0˵����ǰtemp����������һ������
            // ��������Բ��ҿ��Ƿ��ظ�
            sort(temp.begin(), temp.end());
            for (int i = 0; i < ans.size(); ++i)
                if (ans[i] == temp) return;
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < candidates.size(); ++i) {
            temp.push_back(candidates[i]);
            sumTarget(ans, temp, candidates, target - candidates[i]);
            temp.pop_back(); // ÿ�γ�����ɾ��back���²����µ�Ԫ��
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sumTarget(ans, temp, candidates, target);
        return ans;
    }
};


/*
* ����2�����ݵݹ��֦
* ��vector�����ʼ�ݹ�
* �ݹ�ʱ��¼����λ�ý���ݹ��ֻ�ӵ���λ�ÿ�ʼ��������
* ���������һ��ݹ黹��֮ǰ��ʼ ��ô������ظ������ 
*   �����˿ռ临�Ӷ�
* �����������������ڵ���֮���Ѿ�����targetʱ��ֱ���˳� 
*   ������ʱ�临�Ӷ�
* �Ż���� 
*   1084ms ==��12ms��
*   133.5MB ==��11.3MB
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    int begin = 0; // ��¼���¿�ʼ��λ��
    void dfs(const vector<int>& candidates, const int target) {
        if (target == 0) ans.push_back(temp);

        // �������target���ʼ��Ԫ�ػ�С ��ô�Ͳ�Ӧ�ü������������
        for (int i = begin; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            temp.push_back(candidates[i]);
            begin = i;
            dfs(candidates, target - candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target);
        return ans;
    }
};