#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/*
	80. 다익스트라 알고리즘

	아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하는 프로그램을 작성하세요. 
	(경로가 없으면 Impossible를 출력한다)

	▣ 입력설명
	첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연결정보와 거리비용이 주어진다.

	▣ 출력설명
	1번 정점에서 각 정점으로 가는 최소 비용을 2번 정점부터 차례대로 출력하세요.

	▣ 입력예제 1
	6 9
	1 2 12
	1 3 4
	2 1 2
	2 3 5
	2 5 5
	3 4 5
	4 2 2
	4 5 5
	6 4 5

	▣ 출력예제 1
	2 : 11
	3 : 4
	4 : 9
	5 : 14
	6 : impossible
*/

int N, M;
vector<int> vecDist;

vector<vector<pair<int, int>>> path;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> N >> M;
	path.resize(N + 1);

	for (int i = 0; i < N + 1; ++i)
		vecDist.emplace_back(INT_MAX);

	for (int i = 0; i < M; ++i)
	{
		int y = 0, x = 0, value = 0;
		cin >> y >> x >> value;

		path[y].emplace_back(value, x);
	}

	// first : cost, second : edge.
	// 비용(cost) 기준 최소힙 구성.
	pq.emplace(0, 1);
	vecDist[1] = 0;	// 1 --> 1 비용은 0
	
	while (!pq.empty())
	{
		int now = pq.top().second;
		int dist = pq.top().first;

		pq.pop();

		// 현재 정점에서의 누적 거리가 더 크면 수행 X. (최솟값을 찾아야 하므로)
		if (dist > vecDist[now]) continue;

		for (auto& pair : path[now])
		{
			int next = pair.second;				// 현재 정점과 연결되어있는 정점
			int next_sum = dist + pair.first;	// 현재 정점에서 연결된 노드까지의 누적 거리.

			if (vecDist[next] > next_sum)		// 누적값이 더 작은 값이면 갱신.
			{
				vecDist[next] = next_sum;
				pq.emplace(next_sum, next);
			}
		}
	}

	for (int i = 1 ; i < vecDist.size(); ++i)
	{
		if (vecDist[i] == 0) continue;
		if (vecDist[i] != INT_MAX)
			cout << i << " : " << vecDist[i] << endl;
		else
			cout << i << " : impossible" << endl;
	}
}