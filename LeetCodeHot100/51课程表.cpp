/*
* ѡ�� numCourse �ſγ̣���Ϊ 0 �� numCourse-1
* ��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ���ǣ�[0,1]
*/

/*
* ����1�����������������
* ��¼����������Ӧ����ȺͶ�Ӧ����
* ÿ���������Ϊ0��˵������ѧϰ �������
* ���Ӻ����Ӧ�ĳ��Ƚ�����ȶ���1
*/
class Solution1 {
    vector<vector<int>> edges;
    vector<int> indeg;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }
};