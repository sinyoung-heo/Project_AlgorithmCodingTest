#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/*
	70. �׷��� �ִܰŸ�(BFS)
	���� �׷������� 1�� �������� �� �������� ���� �ּ� �̵� �������� ����ϼ���.

	�� �Է¼���
	ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ���������� �־�����.

	�� ��¼���
	1�� �������� �� �������� ���� �ּ� �������� 2�� �������� ���ʴ�� ����ϼ���.

	�� �Է¿��� 1
	6 9
	1 3
	1 4
	2 1
	2 5
	3 4
	4 5
	4 6
	6 2
	6 5

	�� ��¿��� 1
	2 : 3
	3 : 1
	4 : 1
	5 : 2
	6 : 2
*/

int N, M;

map<int, int> answer;

vector<vector<int>> path;
vector<bool> visit;
queue<int> q;

void BFS(int v, int cnt)
{
	q.pop();

	for (int i = 0; i < path[v].size(); ++i)
	{
		int next = path[v][i];

		if (visit[next]) continue;

		visit[next] = true;
		q.push(next);

		// ������ ��尡 ������ ���� �־��ش�.
		auto iter_find = answer.find(next);

		if (iter_find == answer.end())
			answer.emplace(next, cnt);
	}

	if (q.empty())
		return;

	BFS(q.front(), answer[q.front()] + 1);
}

int main()
{
	cin >> N >> M;

	path.resize(N);
	visit.resize(N);

	int y = 0, x = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> y >> x;
		path[y - 1].emplace_back(x - 1);
	}

	visit[0] = true;
	q.push(0);
	BFS(q.front(), 1);

	for (auto& pair : answer)
		cout << pair.first + 1 << " : " << pair.second << endl;
}