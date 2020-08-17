#include <iostream>
#include <vector>

using namespace std;

constexpr int inf = 65536;

vector<vector<int>> Djikstra(vector<vector<int>>& G) {
	// 选用65536表示无穷而非INT_MAX
	// 防止检测min+INT_MAX变为负数反而变为最小的
	int n = G.size();
	vector<int> D(n, inf), P(n, 0), f(n, 0);
	for (int i = 0; i < n; ++i)
		D[i] = G[0][i]; // 首先都初始化为v0直达路径长度
	f[0] = 1;
	int min = inf, k = 0;
	for (int i = 0; i < n; ++i) {
		min = inf;
		for (int j = 1; j < n; ++j)
			if (!f[j] && D[j] < min) {
				// 记下还没做过中间结点的 到v0最近的点
				min = D[j];
				k = j;
			}
		f[k] = 1; // 将这回使用的中间结点标记为用过
		for (int j = 1; j < n; ++j)
			if (!f[j] && min + G[k][j] < D[j]) {
				// 检查没走过的点 发现通过k到达更近则更新
				D[j] = min + G[k][j];
				P[j] = k;
			}
	}
	// 返回D和P D中存储的是v0到每个顶点的最短路径
	return vector<vector<int>>{D, P};
}

int main()
{
	// 驱动测试 以二维矩阵存储点到其它点的距离
	vector<vector<int>> graph{
		{0,1,5,inf,inf,inf,inf,inf,inf},
		{1,0,3,7,5,inf,inf,inf,inf},
		{5,3,0,inf,1,7,inf,inf,inf},
		{inf,7,inf,0,2,inf,3,inf,inf},
		{inf,5,1,2,0,3,6,9,inf},
		{inf,inf,7,inf,3,0,inf,5,inf},
		{inf,inf,inf,3,6,inf,0,2,7},
		{inf,inf,inf,inf,9,5,2,0,4},
		{inf,inf,inf,inf,inf,inf,7,4,0}
	};
	vector<vector<int>> ans = Djikstra(graph);

	// 打印到每个点最短距离
	for (auto d : ans[0])
		cout << d << " ";

	cout << endl;

	// 打印每个点的前驱结点
	for (auto p : ans[1])
		cout << p << " ";

	return 0;
}