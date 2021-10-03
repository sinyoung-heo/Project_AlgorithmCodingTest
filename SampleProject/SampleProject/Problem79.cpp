#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	79. ��������(Prim MST �˰��� : priority_queue Ȱ��)

	�������忡 ������ �����. ���������� �� ���θ� ���������ϴ� ������ �ٴڳ� ���̴�.
	��������� ��� ���ø� ���� �����ϸ鼭 �ּ��� ��������� �鵵�� ���θ� �����ϰ� ���������δ� ����Ϸ��� �Ѵ�.
	�Ʒ��� �׸��� �� �� ���� �����ϴ� �׸��̴�.

	���� ������ �� ���ð� 1���� 9�� ǥ���Ǿ���, ������ �������� �ּҺ�� 196���� ��� ���ø� �����ϴ� ����� ã�Ƴ� ���̴�.

	�� �Է¼���
	ù° �ٿ� ������ ���� V(1��V��25)�� ������ ���� E(1��E��200)�� �־�����. ���� E���� �ٿ�
	�� �� ���ο� ���� ������ ��Ÿ���� �� ���� A, B, C�� �־�����. 
	�̴� A�� ���ÿ� B�� ���ð� ��������� C�� ���η� ����Ǿ� �ִٴ� �ǹ��̴�. C�� ���� 1,000,000�� ���� �ʴ´�.

	�� ��¼���
	��� ���ø� �����ϸ鼭 ��� �ּҺ���� ����Ѵ�.

	�� �Է¿��� 1
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

	�� ��¿��� 1
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

// ����ġ�� �������� �ּ��� ����.
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

		// ������(�����)�̱� ������ 2���� graph ���� ����.
		graph[a].emplace_back(b, value);
		graph[b].emplace_back(a, value);
	}

	pq.push(EDGE(1, 0));

	while (true)
	{
		if (pq.empty()) break;

		EDGE edge = pq.top();
		pq.pop();

		// ���� ������� ���� �����?
		if (!visit[edge.v])
		{
			visit[edge.v] = true;	// ����.
			answer += edge.value;	// ����ġ ����.

			// ���� ���� ����Ǿ��ִ� ��� ��� ť�� push.
			for (auto& link_edge : graph[edge.v])
				pq.push(EDGE(link_edge.v, link_edge.value));
		}
	}

	cout << answer << endl;
}