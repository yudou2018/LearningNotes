#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct EdgeNode {
	int adjvex;
	EdgeNode* next = nullptr;
	EdgeNode(int i) :adjvex(i) {}
};

struct Node {
	int data;
	int in;
	EdgeNode* first = new EdgeNode(-1);
	Node(int d, int i) :data(d), in(i), first(nullptr) {}
};

void TopoSort(vector<Node>& nodes) {
	// 只把入度为0的结点存入栈内
	// 当栈非空时 总是取一个出来输出
	// 并对其箭头下一个node的入度减一
	stack<int> stk;
	for (int i = 0; i < nodes.size(); ++i)
		if (nodes[i].in == 0) stk.push(i);
	while (stk.size()) {
		int i = stk.top();
		stk.pop();
		cout << nodes[i].data << " ";
		EdgeNode* p = nodes[i].first;
		while (p) {
			if (--nodes[p->adjvex].in == 0)
				stk.push(p->adjvex);
			p = p->next;
		}
	}
}

int main()
{
	Node n0(0, 0), n1(1, 0), n2(2, 2), n3(3, 0), n4(4, 2), n5(5, 3), n6(6, 1), n7(7, 2),
		n8(8, 2), n9(9, 1), n10(10, 1), n11(11, 2), n12(12, 1), n13(13, 2);

	EdgeNode* p0 = new EdgeNode(11); p0->next = new EdgeNode(5); p0->next->next = new EdgeNode(4);
	EdgeNode* p1 = new EdgeNode(8); p1->next = new EdgeNode(4); p1->next->next = new EdgeNode(2);
	EdgeNode* p2 = new EdgeNode(9); p2->next = new EdgeNode(6); p2->next->next = new EdgeNode(5);
	EdgeNode* p3 = new EdgeNode(13); p3->next = new EdgeNode(2);
	EdgeNode* p4 = new EdgeNode(7);
	EdgeNode* p5 = new EdgeNode(12); p5->next = new EdgeNode(8);
	EdgeNode* p6 = new EdgeNode(5);
	EdgeNode* p8 = new EdgeNode(7);
	EdgeNode* p9 = new EdgeNode(11); p9->next = new EdgeNode(10);
	EdgeNode* p10 = new EdgeNode(13);
	EdgeNode* p12 = new EdgeNode(9);
	n0.first = p0;
	n1.first = p1; n2.first = p2;
	n3.first = p3; n4.first = p4; n5.first = p5;
	n6.first = p6; n8.first = p8; n9.first = p9;
	n10.first = p10; n12.first = p12;
	vector<Node> nodes{ n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13 };
	TopoSort(nodes);

	return 0;
}