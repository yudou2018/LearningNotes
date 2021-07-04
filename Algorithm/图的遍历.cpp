#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int inf = 65536;

void dfs(const vector<int>& vertex, const vector<vector<int>>& G, const int i) {
	// �ݹ�ʵ�������������
	static vector<int> f(vertex.size(), 1);
	cout << vertex[i] << " ";
	f[i] = 0;
	for (int j = i; j < G[i].size(); ++j) {
		if (f[j] && G[i][j]) dfs(vertex, G, j);
	}
}

void bfs(const vector<int>& vertex, const vector<vector<int>>& G) {
	// �Ը�������Ϊ��� δ̽��������ʼ���й�����ȱ���
	vector<int> f(vertex.size(), 1);
	queue<int> que;
	int p = 0, cnt = 1;
	for (int j = 0; j < vertex.size(); ++j) {
		if (!f[j]) continue;
		que.push(j);
		cnt = 1;
		while (que.size()) {
			while (cnt) {
				p = que.front(), que.pop(), --cnt;
				cout << vertex[p] << " ";
				f[p] = 0;
			}
			for (int i = 0; i < G[p].size(); ++i)
				if (f[i] && G[p][i])
					que.push(i), ++cnt;
		}
	}


}

int main()
{
	vector<int> vertex{ 0,1,2,3,4,5,6,7,8 };
	vector<vector<int>> G{
		{0,1,0,0,0,1,0,0,0},
		{1,0,1,0,0,0,1,0,1},
		{0,1,0,1,0,0,0,0,1},
		{0,0,1,0,1,0,1,1,1},
		{0,0,0,1,0,1,0,1,0},
		{1,0,0,0,1,0,1,0,0},
		{0,1,0,1,0,1,0,1,0},
		{0,0,0,1,1,0,1,0,0},
		{0,1,1,1,0,0,0,0,0}
	};
	// ��0��ʼ����ͼdfs
	//dfs(vertex, G, 0);

	cout << endl;

	// ������ȱ���ͼ
	bfs(vertex, G);

	return 0;
}