#include <iostream>
#include <vector>

using namespace std;

/*
	67. 최소비용(DFS : 인접행렬)

	가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그램을 작성하세요.

	▣ 입력설명
	첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연결정보가 주어진다.

	▣ 출력설명
	최소비용을 출력합니다.

	▣ 입력예제 1
	5 8
	1 2 12
	1 3 6
	1 4 10
	2 3 2
	2 5 2
	3 4 3
	4 2 2
	4 5 5
	▣ 출력예제 1
	13
*/

vector<vector<int>> path;
vector<bool> visit;

int N, M;
int answer = INT_MAX;

void DFS(int v, int sum)
{
	if (v == N - 1)
	{
		if (answer > sum) 
			answer = sum;

		return;
	}

	for (int i = 0; i < path[v].size(); ++i)
	{
		if (path[v][i] == 0) continue;
		if (visit[i]) continue;

		visit[i] = true;

		DFS(i, sum + path[v][i]);

		visit[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	path.resize(N);
	for (auto& vec : path)
		vec.resize(N);

	visit.resize(N);

	int y = 0, x = 0, value = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> y >> x >> value;
		path[y - 1][x - 1] = value;
	}

	visit[0] = true;
	DFS(0, 0);

	cout << answer << endl;
}