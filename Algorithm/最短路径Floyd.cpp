#include <iostream>
#include <vector>

using namespace std;

constexpr int inf = 65536;

vector<vector<vector<int>>> Floyd(vector<vector<int>>& G) {
	int n = G.size();
	vector<vector<int>> D(G), P(n, vector<int>(n, 0));
	// 初始化决定vi一步到vj P记录的是j
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			P[i][j] = j;

	// 查看在上一次最短的基础上
	// 所有路径vj->vk如果经过vi为中转是否又变短了
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (D[j][k] > D[j][i] + D[i][k]) {
					D[j][k] = D[j][i] + D[i][k];

					// j到k经过中间点i了 改为j到i作为前驱
					P[j][k] = P[j][i];
				}
	return vector<vector<vector<int>>>{D, P};
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
	auto ans = Floyd(graph);
	vector<vector<int>> D(ans[0]), P(ans[1]);
	return 0;
}