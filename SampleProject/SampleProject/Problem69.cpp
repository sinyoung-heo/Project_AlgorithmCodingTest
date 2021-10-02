#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	69. 이진트리 넓이우선탐색(BFS)
	아래 그림과 같은 이진트리를 넓이우선탐색해 보세요. 간선 정보 6개를 입력받아 처리해보세요.
		   1
		  2 3
		4 5 6 7
	넓이 우선 탐색 : 1 2 3 4 5 6 7

	▣ 입력예제 1
	1 2
	1 3
	2 4
	2 5
	3 6
	3 7

	▣ 출력예제 1
	1 2 3 4 5 6 7
*/

const int N = 7;
vector<vector<int>> path;
vector<bool> visit;
queue<int> q;

void BFS(int v)
{
	// 노드 방문
	cout << v + 1 << " ";
	q.pop();

	// 연결된 노드 탐색.
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