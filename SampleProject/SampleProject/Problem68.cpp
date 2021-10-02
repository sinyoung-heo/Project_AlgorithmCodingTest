#include <iostream>
#include <vector>

using namespace std;

/*
	68. 최소비용(DFS : 가중치 방향그래프 인접리스트) - STL vector와 pair 구조체 사용.

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