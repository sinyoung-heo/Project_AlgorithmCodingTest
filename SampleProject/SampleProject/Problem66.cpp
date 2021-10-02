#include <iostream>
#include <vector>

using namespace std;

/*
	66. 경로 탐색(DFS : 인접리스트 방법)

	방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프로그램을 작성하세요. 
	아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는
	1 2 3 4 5
	1 2 5
	1 3 4 2 5
	1 3 4 5
	1 4 2 5
	1 4 5
	총 6 가지입니다.

	▣ 입력설명
	첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
	결정보가 주어진다.

	▣ 출력설명
	총 가지수를 출력한다.

	▣ 입력예제 1
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
	▣ 출력예제 1
	6
*/

int N, M;
vector<vector<int>> path;
vector<bool> visit;

int answer;

void DFS(int v)
{
	if (v == N - 1)
	{
		++answer;
		return;
	}

	for (int i = 0; i < path[v].size(); ++i)
	{
		if (path[v][i] == 0) continue;
		if (visit[i]) continue;

		visit[i] = true;
		DFS(i);
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

	int y = 0, x = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> y >> x;
		path[y - 1][x - 1] = 1;
	}

	visit[0] = true;
	DFS(0);

	cout << answer << endl;
}