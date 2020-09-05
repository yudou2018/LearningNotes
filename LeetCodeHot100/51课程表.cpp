/*
* 选修 numCourse 门课程，记为 0 到 numCourse-1
* 想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
*/

/*
* 方法1：广度优先拓扑排序
* 记录所有索引对应的入度和对应出度
* 每次遇到入度为0的说明可以学习 放入队列
* 出队后将其对应的出度结点的入度都减1
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