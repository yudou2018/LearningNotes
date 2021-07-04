#include <iostream>
#include <vector>

using namespace std;

constexpr int inf = 65536;

vector<vector<int>> Djikstra(vector<vector<int>>& G) {
	// ѡ��65536��ʾ�������INT_MAX
	// ��ֹ���min+INT_MAX��Ϊ����������Ϊ��С��
	int n = G.size();
	vector<int> D(n, inf), P(n, 0), f(n, 0);
	for (int i = 0; i < n; ++i)
		D[i] = G[0][i]; // ���ȶ���ʼ��Ϊv0ֱ��·������
	f[0] = 1;
	int min = inf, k = 0;
	for (int i = 0; i < n; ++i) {
		min = inf;
		for (int j = 1; j < n; ++j)
			if (!f[j] && D[j] < min) {
				// ���»�û�����м���� ��v0����ĵ�
				min = D[j];
				k = j;
			}
		f[k] = 1; // �����ʹ�õ��м�����Ϊ�ù�
		for (int j = 1; j < n; ++j)
			if (!f[j] && min + G[k][j] < D[j]) {
				// ���û�߹��ĵ� ����ͨ��k������������
				D[j] = min + G[k][j];
				P[j] = k;
			}
	}
	// ����D��P D�д洢����v0��ÿ����������·��
	return vector<vector<int>>{D, P};
}

int main()
{
	// �������� �Զ�ά����洢�㵽������ľ���
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

	// ��ӡ��ÿ������̾���
	for (auto d : ans[0])
		cout << d << " ";

	cout << endl;

	// ��ӡÿ�����ǰ�����
	for (auto p : ans[1])
		cout << p << " ";

	return 0;
}