#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge {
	Edge(int b, int e, int w) :begin(b), end(e), weight(w) {}
	int begin;
	int end;
	int weight;
};

int Find(vector<int>& parent, int f) {
	while (parent[f] > 0) f = parent[f];
	return f;
}

void KruskalMiniTree(vector<Edge>& edges) {
	// 该方法传入的edges需要是按权值排列的
	// 所以每次优先考虑权值小的边连接 parent数组用于判断是否构成回路
	// 一旦选用一条边 相应的两个顶点会在parent数组中被以索引、元素的形式关联
	// 例如p[k]=i, p[i]=j 如果再传入vi,vj则会导致i索引到j j索引到0这样n==m不会进行连接
	// 或者传入vj vk 会导致p[j]=0, p[k]=i->p[i]=j->p[j]=0 又是n==m不进行连接
	vector<int> parent(edges.size(), 0);
	for (int i = 0; i < edges.size(); ++i) {
		int n = Find(parent, edges[i].begin);
		int m = Find(parent, edges[i].end);
		if (n != m) {
			parent[n] = m;
			cout << "(" << edges[i].begin << ", " << edges[i].end << "): " <<
				edges[i].weight << endl;
		}
	}
	return;
}

int main()
{
	Edge edge0(4, 7, 7), edge1(2, 8, 8), edge2(0, 1, 10), edge3(0, 5, 11),
		edge4(1, 8, 12), edge5(3, 7, 16), edge6(1, 6, 16), edge7(5, 6, 17),
		edge8(1, 2, 18), edge9(6, 7, 19), edge10(3, 4, 20), edge11(3, 8, 21),
		edge12(2, 3, 22), edge13(3, 6, 24), edge14(4, 5, 26);
	vector<Edge> edges{ edge0 ,edge1,edge2,edge3,edge4,edge5,edge6,edge7,
		edge8,edge9,edge10,edge11,edge12,edge13,edge14 };
	KruskalMiniTree(edges);
	return 0;
}