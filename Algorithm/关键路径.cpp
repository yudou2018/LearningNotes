#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct EdgeNode {
	int adjvex = 0;
	int weight = 0;
	EdgeNode* next = nullptr;
	EdgeNode(int ajv = 0, int w = 0, EdgeNode* np = nullptr) :
		adjvex(ajv), weight(w), next(np) {}
};

struct Node {
	int in = 0;
	int data = 0;
	EdgeNode* firstedge = nullptr;
	Node(int i = 0, int d = 0, EdgeNode* pf = nullptr) :
		in(i), data(d), firstedge(pf) {}
};

class Solution {
	// 整个过程要保证所有工序在关键时间内完成
	// 每道工序最早开始时间存放入etv 最晚开始时间存放入ltv
public:
	vector<int> etv;
	stack<int> stk, stk2;
	void topologicalSort(vector<Node>& vec) {
		EdgeNode* e;
		int i, k, gettop;
		int cnt = 0;
		for (int i = 0; i < vec.size(); ++i)
			if (vec[i].in == 0)
				stk.push(i); // 源点入stk
		etv.resize(vec.size(), 0);
		while (stk.size()) {
			gettop = stk.top(), stk.pop();
			stk2.push(gettop);
			++cnt;
			for (e = vec[gettop].firstedge; e; e = e->next) {
				k = e->adjvex;

				// 考虑过vk的入边
				if (--vec[k].in == 0)
					stk.push(k);

				// 更新更大的值作为关键路径
				if (etv[gettop] + e->weight > etv[k])
					etv[k] = etv[gettop] + e->weight;
			}
		}
	}

	void criticalPath(vector<Node>& vec) {
		EdgeNode* e;
		int i, gettop, k, j;
		int ete, lte;
		topologicalSort(vec);
		vector<int> ltv(vec.size(), etv.back());
		while (stk2.size()) {
			gettop = stk2.top(), stk2.pop();
			for (e = vec[gettop].firstedge; e; e = e->next) {
				k = e->adjvex;

				// 更新更小值作为最晚开始时间
				if (ltv[k] - e->weight < ltv[gettop])
					ltv[gettop] = ltv[k] - e->weight;
			}
		}
		// 遍历所有顶点邻接表中的所有弧
		for (j = 0; j < vec.size(); ++j)
			for (e = vec[j].firstedge; e; e = e->next) {
				k = e->adjvex;
				ete = etv[j];
				lte = ltv[k] - e->weight;
				// 找的是vj顶点的最早、最晚开始时间
				// <vj, vk>弧

				// 在某一顶点 最早最晚开始时间相等 则是位于关键路径
				if (ete == lte)
					cout << "<v" << vec[j].data << ", v" << vec[k].data << ">" <<
					" length: " << e->weight << endl;
			}
	}
};


int main()
{
	EdgeNode* e = new EdgeNode(2, 4);
	e->next = new EdgeNode(1, 3); Node n0(0, 0, e);
	e = new EdgeNode(4, 6), e->next = new EdgeNode(3, 5); Node n1(1, 1, e);
	e = new EdgeNode(5, 7), e->next = new EdgeNode(3, 8); Node n2(1, 2, e);
	e = new EdgeNode(4, 3); Node n3(2, 3, e);
	e = new EdgeNode(7, 4), e->next = new EdgeNode(6, 9); Node n4(2, 4, e);
	e = new EdgeNode(7, 6); Node n5(1, 5, e);
	e = new EdgeNode(9, 2); Node n6(1, 6, e);
	e = new EdgeNode(8, 5); Node n7(2, 7, e);
	e = new EdgeNode(9, 3); Node n8(1, 8, e);
	Node n9(2, 9);
	vector<Node> nodeVec{ n0,n1,n2,n3,n4,n5,n6,n7,n8,n9 };
	Solution slt;
	slt.criticalPath(nodeVec);

	return 0;
}