#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int inf = 65536;

// ÿ�ι۲�һ����������б� ѡȡ������̵��������
// ������������̵ı�ѡ����һ������ ����������������̱�
void PrimMiniTree(vector<vector<int>>& G) {
	int n = G.size();

	// һ��ʼ��ʾ���е���v0���ڽ� ����lowcost����v0������ӵ�Ȩֵ
	vector<int> lowcost(G[0]), adjvex(n, 0);
	// adjvex��¼����ѡ����vi���ӵĵ� ��ʼ��Ϊ����v0

	int min = inf, k = 0, j = 1;
	for (int i = 1; i < n; ++i) {
		// iû�����⺬�� ����Ϊ�˿���Ҫѭ������
		min = inf, j = 1, k = 0;

		// �ҵ������Ѽ�¼��Ȩֵ����С��һ�����
		while (j < n) {
			if (lowcost[j] && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
			++j;
		}
		cout << "(" << k << ", " << adjvex[k] << ") " << "Ȩֵ��" << lowcost[k];
		cout << endl;
		lowcost[k] = 0; // ��ʾvk������бߵ���С�Ѿ�ʹ��

		// ��vk������б����� ��Ϊ��һ��ѭ��������С�ߵ�Ŀ��
		for (j = 1; j < n; ++j)
			if (lowcost[j] && G[k][j] < lowcost[j]) {
				// ����һ����������vk, vj��С�ķ���
				lowcost[j] = G[k][j];
				adjvex[j] = k; // vj���ڶ�����Ϊvk
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