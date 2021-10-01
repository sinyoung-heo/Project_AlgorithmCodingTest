#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
	64. ��� Ž��(DFS)

	����׷����� �־����� 1�� �������� N�� �������� ���� ��� ����� ���� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. 
	�Ʒ� �׷������� 1�� �������� 5�� �������� ���� ���� ����
	1 2 3 4 5
	1 2 5
	1 3 4 2 5
	1 3 4 5
	1 4 2 5
	1 4 5
	�� 6 �����Դϴ�.
	�� �Է¼���
	ù° �ٿ��� ������ �� N(1<=N<=20)�� ������ �� M�� �־�����. �� �������� M�ٿ� ���� ��
	�������� �־�����.
	�� ��¼���
	�� �������� ����Ѵ�.
	�� �Է¿��� 1
	5 9
	1 2
	1 3
	1 4
	2 1
	2 3
	2 5
	3 4
	4 2
	4 5
	�� ��¿��� 1
	6
*/

int N, M;

int cnt;
vector<vector<int>> path;
vector<bool> visit;

void DFS(int v)
{
	if (v == N - 1)
	{
		++cnt;
		cout << endl;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (path[v][i] == 1 && !visit[i])
		{
			visit[i] = true;
			DFS(i);
			visit[i] = false;
		}
	}

}

int main()
{
	cin >> N >> M;

	path.resize(N);
	visit.resize(N);

	for (auto& vec : path)
		vec.resize(N);

	int y = 0, x = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> y >> x;
		path[y - 1][x - 1] = 1;
	}

	visit[0] = true;
	DFS(0);

	cout << cnt << endl;
}