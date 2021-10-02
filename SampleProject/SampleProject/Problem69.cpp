#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	69. ����Ʈ�� ���̿켱Ž��(BFS)
	�Ʒ� �׸��� ���� ����Ʈ���� ���̿켱Ž���� ������. ���� ���� 6���� �Է¹޾� ó���غ�����.
		   1
		  2 3
		4 5 6 7
	���� �켱 Ž�� : 1 2 3 4 5 6 7

	�� �Է¿��� 1
	1 2
	1 3
	2 4
	2 5
	3 6
	3 7

	�� ��¿��� 1
	1 2 3 4 5 6 7
*/

const int N = 7;
vector<vector<int>> path;
vector<bool> visit;
queue<int> q;

void BFS(int v)
{
	// ��� �湮
	cout << v + 1 << " ";
	q.pop();

	// ����� ��� Ž��.
	for (int i = 0; i < path[v].size(); ++i)
	{
		int next = path[v][i];

		if (visit[next]) continue;

		visit[next] = true;
		q.push(next);
	}

	if (q.empty())
		return;

	BFS(q.front());
}

int main()
{
	path.resize(N);
	visit.resize(N);

	int y = 0, x = 0;
	for (int i = 0; i < 6; ++i)
	{
		cin >> y >> x;
		path[y - 1].emplace_back(x - 1);
	}

	q.push(0);
	visit[0] = true;
	BFS(q.front());
}