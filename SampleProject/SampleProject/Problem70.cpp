#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/*
	70. 그래프 최단거리(BFS)
	다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.

	▣ 입력설명
	첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연결정보가 주어진다.

	▣ 출력설명
	1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.

	▣ 입력예제 1
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

	▣ 출력예제 1
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

		// 도착한 노드가 없으면 값을 넣어준다.
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