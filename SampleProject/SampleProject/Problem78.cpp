#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	78. 원더랜드(Kruskal MST 알고리즘 : Union & Find 활용)

	원더랜드에 문제가 생겼다. 원더랜드의 각 도로를 유지보수하는 재정이 바닥난 것이다.
	원더랜드는 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 도로를 선택하고 나머지도로는 폐쇄하려고 한다.
	아래의 그림은 그 한 예를 설명하는 그림이다.

	위의 지도는 각 도시가 1부터 9로 표현되었고, 지도의 오른쪽은 최소비용 196으로 모든 도시를 연결하는 방법을 찾아낸 것이다.

	▣ 입력설명
	첫째 줄에 도시의 개수 V(1 ≤V≤ 25)와 도로의 개수 E(1 ≤ E ≤ 200가 주어진다. 
	다음 E개의 줄에는 각 도로에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
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
		: v1(0), v2(0), value(0) 
	{}
	tagEdge(const int& v1, const int& v2, const int& value)
		: v1{ v1 }, v2{ v2 }, value{ value }
	{}

	bool operator<(tagEdge& rhs) { return value < rhs.value; }

	int v1, v2, value;

}EDGE;

vector<int> unf;
vector<EDGE> graph;


int Find(int v)
{
	if (v == unf[v])
		return v;
	else
		return unf[v] = Find(unf[v]);	// 집합의 Root를 찾아 나간다.
}

void Union(EDGE& edge)
{
	int a = Find(edge.v1);
	int b = Find(edge.v2);

	// 서로 다른 집합이면 같은 집합으로 만든다.
	if (a != b)
		unf[a] = b;
}

int main()
{
	cin >> V >> E;
	
	unf.resize(V + 1);
	for (int i = 1; i <= V; ++i)
		unf[i] = i;

	for (int i = 0; i < E; ++i)
	{
		int a = 0, b = 0, value = 0;
		cin >> a >> b >> value;
		graph.emplace_back(a, b, value);
	}

	// value(비용)을 기준으로 벡터를 정렬한다.
	sort(graph.begin(), graph.end());

	for (auto& edge : graph)
	{
		int a = Find(edge.v1);
		int b = Find(edge.v2);

		// 서로 다른 집합이면, 같은 집합으로 Union화 한다.
		// 그리고 가중치를 누적한다.
		if (a != b)
		{
			answer += edge.value;
			Union(edge);
		}
	}

	cout << answer << endl;
}
