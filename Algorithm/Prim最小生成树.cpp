#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int inf = 65536;

// 每次观察一个顶点的所有边 选取其中最短的那条输出
// 并沿着这条最短的边选择另一个顶点 继续找这个顶点的最短边
void PrimMiniTree(vector<vector<int>>& G) {
	int n = G.size();

	// 一开始表示所有点与v0相邻接 其中lowcost就是v0与点连接的权值
	vector<int> lowcost(G[0]), adjvex(n, 0);
	// adjvex记录当下选择与vi连接的点 初始化为都是v0

	int min = inf, k = 0, j = 1;
	for (int i = 1; i < n; ++i) {
		// i没有特殊含义 单纯为了控制要循环几次
		min = inf, j = 1, k = 0;

		// 找到当下已记录的权值中最小的一个输出
		while (j < n) {
			if (lowcost[j] && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
			++j;
		}
		cout << "(" << k << ", " << adjvex[k] << ") " << "权值：" << lowcost[k];
		cout << endl;
		lowcost[k] = 0; // 表示vk结点所有边的最小已经使用

		// 把vk点的所有边纳入 作为下一次循环中找最小边的目标
		for (j = 1; j < n; ++j)
			if (lowcost[j] && G[k][j] < lowcost[j]) {
				// 把下一批边里连接vk, vj更小的放入
				lowcost[j] = G[k][j];
				adjvex[j] = k; // vj的邻顶点设为vk
			}
	}
}

int main()
{
	vector<int> vertex{ 0,1,2,3,4,5,6,7,8 };
	vector<vector<int>> G{
		{0,10,inf,inf,inf,11,inf,inf,inf},
		{10,0,18,inf,inf,inf,16,inf,12},
		{inf,18,0,22,inf,inf,inf,inf,8},
		{inf,inf,22,0,20,inf,24,16,21},
		{inf,inf,inf,20,0,26,inf,7,inf},
		{11,inf,inf,inf,26,0,17,inf,inf},
		{inf,16,inf,24,inf,17,0,19,inf},
		{inf,inf,inf,16,7,inf,19,0,inf},
		{inf,12,8,21,inf,inf,inf,inf,0}
	};
	PrimMiniTree(G);
	return 0;
}