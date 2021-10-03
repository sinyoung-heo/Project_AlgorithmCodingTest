#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	79. 원더랜드(Prim MST 알고리즘 : priority_queue 활용)

	원더랜드에 문제가 생겼다. 원더랜드의 각 도로를 유지보수하는 재정이 바닥난 것이다.
	원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지도로는 폐쇄하려고 한다.
	아래의 그림은 그 한 예를 설명하는 그림이다.

	위의 지도는 각 도시가 1부터 9로 표현되었고, 지도의 오른쪽은 최소비용 196으로 모든 도시를 연결하는 방법을 찾아낸 것이다.

	▣ 입력설명
	첫째 줄에 도시의 개수 V(1≤V≤25)와 도로의 개수 E(1≤E≤200)가 주어진다. 다음 E개의 줄에
	는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
	이는 A번 도시와 B번 도시가 유지비용이 C인 도로로 연결되어 있다는 의미이다. C는 값이 1,000,000을 넘지 않는다.

	▣ 출력설명
	모든 도시를 연결하면서 드는 최소비용을 출려한다.

	▣ 입력예제 1
	9 12
	1 2 12
	1 9 25
	2 3 10
	2 8 17
	2 9 8
	3 4 18
	3 7 55
	4 5 44
	5 6 60
	5 7 38
	7 8 35
	8 9 15

	▣ 출력예제 1
	196
*/

int answer;
int V, E;

typedef struct tagEdge
{
	tagEdge()
		: v(0), value(0)
	{}
	tagEdge(const int& v, const int& value)
		: v{ v }, value{ value }
	{}
	tagEdge(const tagEdge& rhs)
		: v{ rhs.v }, value{ rhs.value }
	{}
	tagEdge(tagEdge&& rhs)
		: v{ rhs.v }, value{ rhs.value }
	{}

	bool operator<(const tagEdge& rhs) const { return value < rhs.value; }
	bool operator>(const tagEdge& rhs) const { return value > rhs.value; }
	void operator=(const tagEdge& rhs)
	{ 
		v = rhs.v;
		value = rhs.value;
	}

	int v, value;
}EDGE;

vector<vector<EDGE>> graph;
vector<bool> visit;

// 가중치를 기준으로 최소힙 구성.
priority_queue<EDGE, vector<EDGE>, greater<EDGE>> pq;

int main()
{
	cin >> V >> E;

	graph.resize(V + 1);
	visit.resize(V + 1);

	for (int i = 0; i < E; ++i)
	{
		int a = 0, b = 0, value = 0;
		cin >> a >> b >> value;

		// 무방향(양방향)이기 때문에 2개의 graph 정보 생성.
		graph[a].emplace_back(b, value);
		graph[b].emplace_back(a, value);
	}

	pq.push(EDGE(1, 0));

	while (true)
	{
		if (pq.empty()) break;

		EDGE edge = pq.top();
		pq.pop();

		// 아직 연결되지 않은 노드라면?
		if (!visit[edge.v])
		{
			visit[edge.v] = true;	// 연결.
			answer += edge.value;	// 가중치 누적.

			// 현재 노드와 연결되어있는 모든 노드 큐에 push.
			for (auto& link_edge : graph[edge.v])
				pq.push(EDGE(link_edge.v, link_edge.value));
		}
	}

	cout << answer << endl;
}