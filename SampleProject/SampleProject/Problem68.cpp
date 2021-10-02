#include <iostream>
#include <vector>

using namespace std;

/*
	68. �ּҺ��(DFS : ����ġ ����׷��� ��������Ʈ) - STL vector�� pair ����ü ���.

	����ġ ����׷����� �־����� 1�� �������� N�� �������� ���� �ּҺ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

	�� �Է¼���
	ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ���������� �־�����.

	�� ��¼���
	�ּҺ���� ����մϴ�.

	�� �Է¿��� 1
	5 8
	1 2 12
	1 3 6
	1 4 10
	2 3 2
	2 5 2
	3 4 3
	4 2 2
	4 5 5

	�� ��¿��� 1
	13
*/

int N, M;
vector<vector<pair<int, int>>> path;
vector<bool> visit;

int answer = INT_MAX;

void DFS(int v, int sum)
{
	if (v == N - 1)
	{
		if (answer > sum)
			answer = sum;

		return;
	}

	for (auto& pair : path[v])
	{
		if (visit[pair.first]) continue;

		visit[pair.first] = true;

		DFS(pair.first, pair.second + sum);

		visit[pair.first] = false;
	}
}

int main()
{
	cin >> N >> M;
	path.resize(N);
	visit.resize(N);

	int y = 0, x = 0, value = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> y >> x >> value;
		path[y - 1].emplace_back(x - 1, value);
	}

	visit[0] = true;
	DFS(0, 0);

	cout << answer << endl;
}